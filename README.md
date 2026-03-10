# 📦 CONTAINER TRACKER v1.0

A simple retro-style C++ console application for tracking shipping containers.

## Features

| Option | Description |
|--------|-------------|
| 1 | **Register Container** - Add new container with ID, type, size, location, status |
| 2 | **Update Location** - Change container location |
| 3 | **Update Status** - Change container status |
| 4 | **View All** - Display all registered containers in a table |
| 5 | **View History** - Track location/status changes per container |
| 6 | **Generate Report** - Summary by status and type |
| 7 | **Exit** - Close the application |

## Container Data

- **Types:** `DRY`, `REEFER`, `TANK`
- **Sizes:** `20FT`, `40FT`
- **Statuses:** `IN TRANSIT`, `DOCKED`, `DELIVERED`

## Build & Run

```bash
# Compile
g++ -std=c++11 -o container_tracker container_tracker.cpp

# Run
./container_tracker
```

## Project Structure

```
CPP Case Study/
├── container_tracker.cpp    # Single source file (177 lines)
├── container_tracker        # Compiled executable
└── README.md                # This file
```

## Technical Details

- **Language:** C++11
- **Lines of Code:** 177
- **Data Storage:** Parallel arrays (max 100 containers)
- **History:** Up to 10 entries per container
- **Libraries:** `<iostream>`, `<string>`
- **No classes, structs, or external dependencies**

## Sample Output

```
==============================
  CONTAINER TRACKER v1.0
==============================
1. REGISTER CONTAINER
2. UPDATE LOCATION
3. UPDATE STATUS
4. VIEW ALL
5. VIEW HISTORY
6. GENERATE REPORT
7. EXIT
==============================
CHOICE: _
```

---

*Beginner-friendly C++ project demonstrating parallel arrays, functions, and console I/O.*
