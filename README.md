# Naadya
A minimal, custom programming language built from scratch — featuring a hand-written lexer, parser, and support for expressions, control flow, and user-defined functions.

---

## Current Status

The project is currently in an early stage and **only performs tokenizing (lexical analysis)** of source code.

---
### Repository Structure

```

├── build/          # Compiled object files and binary
├── include/        # Header files
├── scripts/        # Sample Naadya scripts (e.g. myscript.ndy)
├── src/            # Source code (.cpp files)
├── Makefile        # Build and run automation
├── README.md       # This file
└── .gitignore      # Git ignore rules

````

---

### Requirements

- C++17 compatible compiler (e.g. g++)
- Make utility

---

### Build Instructions

Run the following command in the root directory to build the interpreter:

```sh
make
````

This will compile the source files and generate the executable at `build/naadya`.

---

### Running a Naadya Script

You can run a .ndy script by providing the script filename as a command-line argument to the interpreter:

```sh
./build/naadya path/to/your_script.ndy
````

For example:
```sh
./build/naadya scripts/myscript.ndy
````

Or simply use the make run command to run the sample script:
```sh
make run
````

This runs the interpreter on `scripts/myscript.ndy`.

---

### Cleaning Build Artifacts

To clean all compiled files and binaries:

```sh
make clean
```

---

### Rebuild and Run

To clean, build, and run the sample script all in one:

```sh
make rebuild
```

---

### Sample Script (scripts/myscript.ndy)

```naadya
# initialize the variable
pi := 3.141592

x := 8.23

if x >= 0 then
    println('x is positive')
else
    println('x is negative')
end
```
