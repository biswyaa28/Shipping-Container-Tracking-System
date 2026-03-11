# 📦 Shipping Container Tracking System — Retro C++ Edition

> A minimalist, single-file C++ console application that tracks shipping containers with 1980s terminal aesthetics. Built for ITM Skills University Case Study 46.

![Retro Terminal Demo](https://img.shields.io/badge/Style-Retro_Green_On_Black-39FF14?style=flat-square)
![Lines of Code](https://img.shields.io/badge/Lines-177-green?style=flat-square)
![C++ Standard](https://img.shields.io/badge/C%2B%2B-C%2B%2B11-blue?style=flat-square)

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

## ✨ Features

- ✅ **Single-file implementation** — Only `container_tracker.cpp` (no headers, no classes)
- ✅ **Retro terminal UI** — Green-on-black ANSI colors, ASCII borders, uppercase prompts
- ✅ **Complete functionality**:
  - Register containers (`DRY`/`REEFER`/`TANK` types, `20FT`/`40FT` sizes)
  - Update location & status in real-time
  - View all containers in tabular format
  - Track 10 history entries per container
  - Generate status/type reports
- ✅ **Beginner-friendly** — Pure procedural C++ with parallel arrays
- ✅ **Zero dependencies** — Only `<iostream>` and `<string>` required

## ⚙️ Quick Start

### Compile
```bash
g++ -std=c++11 -o container_tracker container_tracker.cpp
```

### Run
```bash
./container_tracker
```

> 💡 **Windows users**: Use Git Bash, WSL, or MinGW. For Command Prompt, remove `\033[32m` green text code in `show_menu()`.

## 🖥️ Usage Guide

| Option | Action | Example Input |
|--------|--------|---------------|
| `1` | Register new container | `ID: CONT001` → `TYPE: DRY` → `SIZE: 20FT` → `LOCATION: SINGAPORE` → `STATUS: IN TRANSIT` |
| `2` | Update location | `ID: CONT001` → `NEW LOCATION: ROTTERDAM` |
| `3` | Update status | `ID: CONT001` → `NEW STATUS: DOCKED` |
| `4` | View all containers | Shows tabular list with ID/Type/Size/Location/Status |
| `5` | View history | Shows chronological log: `1. REGISTERED AT SINGAPORE` → `2. MOVED TO ROTTERDAM` |
| `6` | Generate report | Summary counts by status & container type |
| `7` | Exit | Closes application |

### Sample Workflow
```
CHOICE: 1
--- REGISTER CONTAINER ---
CONTAINER ID: CONT001
TYPE (DRY/REEFER/TANK): DRY
SIZE (20FT/40FT): 20FT
LOCATION: NEW YORK
STATUS (IN TRANSIT/DOCKED/DELIVERED): IN TRANSIT
CONTAINER REGISTERED SUCCESSFULLY!
ID: CONT001 | TYPE: DRY | SIZE: 20FT

PRESS ENTER TO CONTINUE...
```

## 🧠 Technical Specifications

| Aspect | Detail |
|--------|--------|
| **Language** | C++11 (ISO/IEC 14882:2011) |
| **Lines of Code** | 177 (excluding comments) |
| **Architecture** | Procedural (no OOP) |
| **Data Storage** | Parallel arrays (`string ids[100]`, `string history[100][10]`, etc.) |
| **Memory Limit** | 100 containers max, 10 history entries each |
| **Libraries** | `<iostream>`, `<string>` only |
| **Design Philosophy** | Simplicity > abstraction; educational clarity > "best practices" |

## 🎓 Educational Value

This project demonstrates core C++ concepts ideal for beginners:

```cpp
// Parallel arrays instead of structs/classes
string ids[100], types[100], sizes[100];  // Simple & explainable

// Modular functions without OOP overhead
void register_container() { ... }  // Clear purpose, easy to trace

// Fixed-size arrays for predictable memory
string history[100][10];  // No dynamic allocation complexity
```

**Perfect for learning:**
- Console I/O (`cin`/`cout`)
- Array manipulation
- Function decomposition
- Input validation loops
- ANSI escape codes (`\033[32m` for green text)
- `printf()` formatting for tabular output

## 📁 Project Structure

```
CPP Case Study/
├── container_tracker.cpp    # Single source file (177 lines)
├── container_tracker        # Compiled executable
└── README.md                # This file
```

## 🚀 Why This Approach?

> *"Simplicity is the ultimate sophistication."* — Leonardo da Vinci

While modern projects use classes, databases, and web frameworks, this implementation proves that **educational value comes from clarity—not complexity**. By avoiding OOP abstractions, students can:

1. Trace every variable in memory
2. Understand program flow without indirection
3. Modify functionality without fighting framework constraints
4. Compile and run with a single command

## 📜 License

MIT License — Free to use, modify, and share for educational purposes.

---

> 💡 **Pro Tip**: Record your terminal session with [asciinema.org](https://asciinema.org) and embed it in your README for an interactive demo!

```markdown
[![asciicast](https://asciinema.org/a/XXXXXX.svg)](https://asciinema.org/a/XXXXXX)
```

---

*© 2026 ITM Skills University • Case Study 46 • Retro Computing Division*  
*Green text since 1987™* 💚
