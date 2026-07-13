# DSA Semester Project
Data Structures and Algorithms Lab (CSL 221)

**Students Name:** Hasan Zahid & Waleed Ahmed Razzaqi
**Enrollment #:** 01-131232-028 & 093
**Teacher:** Engr. Raheela Ambrin
**Dept of SE, BUIC**

---

## Project: Password Manager

A desktop password manager built with **C++** and the **Qt Widgets** framework, developed to demonstrate practical, from-scratch implementations of core data structures and algorithms taught in CSL 221 — rather than relying on the STL equivalents for the core logic.

The application lets a user log in with a master password and then add, view, search, and delete saved account credentials, with entries persisted to disk between sessions. A companion "Data Structures Playground" panel exposes each underlying structure directly, so the DSA operations behind the scenes can be exercised and observed independently of the password-manager workflow.

## Features

- **Master password login** — a login gate must be passed before the main dashboard is shown.
- **Add / Update credentials** — add a new account and password, or update the password of an existing account.
- **View credentials** — list all saved accounts and passwords.
- **Search credentials** — look up the password for a given account name.
- **Delete credentials** — remove a saved account.
- **Password generator** — generate a random strong password (letters, digits, and symbols).
- **Persistence** — entries are saved to and loaded from a local `passwords.txt` file automatically.
- **Data Structures Playground** — interactive demo panel for the Stack, Queue, Binary Search Tree, and Graph implementations (push/pop, enqueue/dequeue, insert/search/delete, add edge/DFS/BFS).

## Data Structures & Algorithms Used

| Structure / Algorithm | Where it's used | Purpose |
|---|---|---|
| **Singly Linked List** | `LinkedList` | Stores the actual account/password entries shown in the credential list. |
| **Stack** (array-based) | `Stack` | Keeps a LIFO history of recently added `account:password` entries; also exposed standalone in the playground. |
| **Queue** (circular array-based) | `Queue` | Keeps a FIFO history of recently added entries; also exposed standalone in the playground. |
| **Binary Search Tree** | `BST` | Indexes account names for fast insert/search/delete, kept in sync when entries are added or removed. |
| **Graph + DFS/BFS** | `Graph` | Adjacency-list graph supporting depth-first and breadth-first traversal, demonstrated in the playground. |

## Project Structure

```
Password-Manager/
├── Qt Gui/                       # Main Qt Widgets application (this build)
│   ├── App.cpp / App.h           # QApplication subclass, app entry setup
│   ├── Main.cpp                  # main() — launches the app and MainWindow
│   ├── LoginDialog.cpp / .h      # Master password login dialog
│   ├── MainWindow.cpp / .h       # Main dashboard: entries UI + DSA playground
│   ├── PasswordManagerBackend.cpp / .h   # Ties the DSA structures together for the credential store
│   ├── LinkedList.cpp / .h
│   ├── Stack.cpp / .h
│   ├── Queue.cpp / .h
│   ├── BST.cpp / .h
│   ├── Graph.cpp / .h
│   ├── DSA_Project.pro           # qmake project file
│   ├── master_password.txt       # Stores the master password (plain text — see Known Limitations)
│   └── passwords.txt             # Generated at runtime; stores saved credentials
│
└── Console Based/                # Earlier console prototype (separate MySQL-backed variant)
```

## Requirements

- Qt 5 (Widgets module) — `qtbase5-dev` and `qt5-qmake` on Debian/Ubuntu, or the Qt 5/6 MinGW/MSVC kit via Qt Creator on Windows.
- A C++11-compatible compiler (g++, MinGW, or MSVC).

## Build & Run

**Using Qt Creator (recommended):**
1. Open `DSA_Project.pro` in Qt Creator.
2. Select a configured Qt kit (Desktop Qt 5/6, MinGW or MSVC).
3. Build and Run (Ctrl+R).

**From the command line (Linux/macOS):**
```bash
cd "Qt Gui"
qmake DSA_Project.pro
make
./DSA_Project
```

**From the command line (Windows, with Qt's MinGW toolchain on PATH):**
```bash
cd "Qt Gui"
qmake DSA_Project.pro
mingw32-make
DSA_Project.exe
```

On first login, enter the master password stored in `master_password.txt` (default: `Admin`).

## Known Limitations

- The master password and saved credentials are stored as **plain text** on disk. This is acceptable for a lab/demo project but is **not secure** for real-world use — a production version would hash the master password and encrypt stored credentials.
- The `.ui` files in the project (`login_dialog.ui`, `mainwindow.ui`, `add_entry.ui`, `view_entries.ui`) are legacy Qt Designer forms kept for reference; the current UI is built entirely in code (`MainWindow.cpp`, `LoginDialog.cpp`), so these files are not compiled into the running UI.
- The "Console Based" folder is a separate, earlier prototype that connects to a MySQL database and is not wired into the Qt GUI.

## Possible Future Improvements

- Hash the master password (e.g. with a salted hash) instead of storing it in plain text.
- Encrypt saved credentials at rest.
- Use the BST/Graph structures to power actual search/relationship features in the credential view, rather than only in the standalone playground.
- Add unit tests for each data structure.