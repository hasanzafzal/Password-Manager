CREATE DATABASE IF NOT EXISTS SpaceSaver;
USE SpaceSaver;

CREATE TABLE IF NOT EXISTS Vehicles 
(
    vehicleNum VARCHAR(15) PRIMARY KEY,
    ownerName VARCHAR(100) NOT NULL,
    contactNum BIGINT NOT NULL CHECK (contactNum >= 1000000000),
    vehicleType ENUM('FourWheeler', 'TwoWheeler') NOT NULL,
    hasCarrier BOOLEAN NOT NULL DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS ParkingSlots 
(
    slotID INT AUTO_INCREMENT PRIMARY KEY,
    slotType ENUM('Car', 'Bike') NOT NULL,
    isOccupied BOOLEAN NOT NULL DEFAULT FALSE
);

CREATE TABLE IF NOT EXISTS Tickets 
(
    ticketID INT AUTO_INCREMENT PRIMARY KEY,
    entryTime DATETIME NOT NULL,
    exitTime DATETIME,
    duration INT CHECK (duration IS NULL OR duration >= 0),
    vehicleNum VARCHAR(15) NOT NULL,
    FOREIGN KEY (vehicleNum) REFERENCES Vehicles(vehicleNum) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS Alerts 
(
    alertID INT AUTO_INCREMENT PRIMARY KEY,
    vehicleNum VARCHAR(15),
    message TEXT NOT NULL,
    alertTime TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO ParkingSlots (slotType, isOccupied)
VALUES 
   ('Car', FALSE), ('Bike', FALSE), ('Car', FALSE), ('Bike', FALSE), ('Car', FALSE);

CREATE OR REPLACE VIEW AvailableSlots AS
SELECT slotID, slotType
FROM ParkingSlots
WHERE isOccupied = FALSE;

DELIMITER //

CREATE PROCEDURE RegisterVehicle 
(
    IN p_vehicleNum VARCHAR(15),
    IN p_ownerName VARCHAR(100),
    IN p_contactNum BIGINT,
    IN p_vehicleType VARCHAR(15),
    IN p_hasCarrier BOOLEAN
)
BEGIN
    DECLARE slotId INT;
    DECLARE slotTypeNeeded ENUM('Car', 'Bike');

    IF p_vehicleType = 'FourWheeler' THEN
        SET slotTypeNeeded = 'Car';
    ELSE
        SET slotTypeNeeded = 'Bike';
    END IF;
    SELECT slotID INTO slotId
    FROM ParkingSlots
    WHERE isOccupied = FALSE AND slotType = slotTypeNeeded
    LIMIT 1;
    IF slotId IS NOT NULL THEN
        INSERT INTO Vehicles(vehicleNum, ownerName, contactNum, vehicleType, hasCarrier)
        VALUES (p_vehicleNum, p_ownerName, p_contactNum, p_vehicleType, p_hasCarrier);
        UPDATE ParkingSlots SET isOccupied = TRUE WHERE slotID = slotId;
        INSERT INTO Tickets(entryTime, vehicleNum)
        VALUES (NOW(), p_vehicleNum);
    ELSE
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'No suitable parking slot available.';
    END IF;
END //

DELIMITER ;

DELIMITER //

CREATE PROCEDURE ExitVehicle 
(
    IN p_vehicleNum VARCHAR(15)
)
BEGIN
    DECLARE v_entryTime DATETIME;
    DECLARE v_exitTime DATETIME;
    DECLARE v_duration INT;
    DECLARE ticketId INT;
    SET v_exitTime = NOW();
    SELECT entryTime, ticketID INTO v_entryTime, ticketId
    FROM Tickets
    WHERE vehicleNum = p_vehicleNum AND exitTime IS NULL
    ORDER BY entryTime DESC LIMIT 1;
    SET v_duration = TIMESTAMPDIFF(HOUR, v_entryTime, v_exitTime);
    UPDATE Tickets
    SET exitTime = v_exitTime, duration = v_duration
    WHERE ticketID = ticketId;
    UPDATE ParkingSlots
    SET isOccupied = FALSE
    WHERE slotID = 
    (
        SELECT ps.slotID
        FROM ParkingSlots ps
        JOIN Tickets t ON t.vehicleNum = p_vehicleNum
        WHERE ps.isOccupied = TRUE
        ORDER BY t.entryTime DESC
        LIMIT 1
    );
END //

DELIMITER ;

DELIMITER //

CREATE FUNCTION TotalRevenue()
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE total DECIMAL(10,2);
    SELECT IFNULL(SUM(duration * 10), 0) INTO total FROM Tickets WHERE duration IS NOT NULL;
    RETURN total;
END //

DELIMITER ;

DELIMITER //

CREATE EVENT IF NOT EXISTS LongParkingAlert
ON SCHEDULE EVERY 15 MINUTE
DO
BEGIN
    INSERT INTO Alerts(vehicleNum, message)
    SELECT vehicleNum, CONCAT('Vehicle ', vehicleNum, ' parked more than 2 hours.')
    FROM Tickets
    WHERE exitTime IS NULL
      AND TIMESTAMPDIFF(HOUR, entryTime, NOW()) > 2
      AND vehicleNum NOT IN (
          SELECT vehicleNum FROM Alerts
          WHERE alertTime >= NOW() - INTERVAL 1 HOUR
      );
END //

DELIMITER ;

CREATE INDEX idx_vehicleNum ON Vehicles(vehicleNum);
CREATE INDEX idx_entryTime ON Tickets(entryTime);
CREATE INDEX idx_slotOccupied ON ParkingSlots(isOccupied);
CREATE INDEX idx_ticket_vehicle ON Tickets(vehicleNum);