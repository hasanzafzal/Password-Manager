CREATE DATABASE IF NOT EXISTS PasswordManager;
USE PasswordManager;

CREATE TABLE IF NOT EXISTS Users 
(
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL, -- Store hashed password
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS Credentials 
(
    credential_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    service_name VARCHAR(100) NOT NULL,
    service_username VARCHAR(100) NOT NULL,
    service_password TEXT NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE
);

DELIMITER //
CREATE PROCEDURE RegisterUser
(
    IN p_username VARCHAR(50),
    IN p_password_hash VARCHAR(255)
)
BEGIN
    INSERT INTO Users (username, password_hash)
    VALUES (p_username, p_password_hash);
END;
//
DELIMITER ;

DELIMITER //
CREATE FUNCTION LoginUser
(
    p_username VARCHAR(50),
    p_password_hash VARCHAR(255)
) RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE uid INT;
    SELECT user_id INTO uid
    FROM Users
    WHERE username = p_username AND password_hash = p_password_hash;
    RETURN IFNULL(uid, -1); -- Return -1 if login fails
END;
//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE AddCredential
(
    IN p_user_id INT,
    IN p_service_name VARCHAR(100),
    IN p_service_username VARCHAR(100),
    IN p_service_password TEXT
)
BEGIN
    INSERT INTO Credentials (user_id, service_name, service_username, service_password)
    VALUES (p_user_id, p_service_name, p_service_username, p_service_password);
END;
//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE ViewCredentials
(
    IN p_user_id INT
)
BEGIN
    SELECT credential_id, service_name, service_username, service_password, created_at
    FROM Credentials
    WHERE user_id = p_user_id;
END;
//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE UpdateCredential
(
    IN p_credential_id INT,
    IN p_service_username VARCHAR(100),
    IN p_service_password TEXT
)
BEGIN
    UPDATE Credentials
    SET service_username = p_service_username,
        service_password = p_service_password
    WHERE credential_id = p_credential_id;
END;
//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE DeleteCredential
(
    IN p_credential_id INT
)
BEGIN
    DELETE FROM Credentials
    WHERE credential_id = p_credential_id;
END;
//
DELIMITER ;

DELIMITER //
CREATE PROCEDURE Application
(
    IN p_username VARCHAR(50),
    IN p_password_hash VARCHAR(255)
)
BEGIN
    DECLARE uid INT;
    SET uid = LoginUser(p_username, p_password_hash);
    IF uid = -1 THEN
        SELECT 'Login Failed' AS Status;
    ELSE
        SELECT 'Login Successful' AS Status;
        CALL ViewCredentials(uid);
    END IF;
END;
//
DELIMITER ;
