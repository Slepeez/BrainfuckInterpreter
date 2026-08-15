# Modular Brainfuck Interpreter in C

A modular, clean, and highly efficient **Brainfuck Interpreter** built from scratch in C. This project simulates a low-level Virtual Machine (VM) featuring a classical Turing-complete tape model, robust memory safety bounds, and an optimized execution engine using a pre-computed Jump Table.

This project was built to master multi-file architecture in C, advanced pointer manipulation, custom memory management, and automated build pipelines using **CMake**.

##  Architectural & Engineering Highlights

*   **$O(1)$ Loop Jump Table:** Instead of naively scanning text back and forth at runtime during loops (`[` and `]`), the engine pre-computes matching bracket offsets during an initial phase. This achieves a time complexity of $O(1)$ for loop jumps, drastically improving execution speed compared to beginner-level interpreters.
*   **Custom Modular Stack:** Built a dedicated, dynamically-allocated **Stack structure** with cleanly decoupled interface boundaries (`stack.h`) and domain logic (`stack.c`) to handle loop-parsing state safely.
*   **Memory-Safe Tape:** Implements the industry-standard 30,000-byte cell tape layout equipped with strict runtime bounds checking to safely prevent undefined behavior, segmentation faults, and out-of-bounds pointer vulnerabilities.
*   **Low-Level I/O & Memory Control:** Features direct file-to-RAM streaming via `fread`, precise memory allocation tracking using `malloc`/`free`, and byte-by-byte input handling using native standard I/O functions.

##  Compilation & Build Pipeline

The project uses modern cross-platform **CMake** configurations. To compile the codebase natively on Linux using GCC or Clang, follow the standard out-of-source build pattern below:

```bash
# 1. Create and enter the temporary build directory
mkdir build && cd build

# 2. Configure the native build system files via CMake
cmake ..

# 3. Compile the binary executable
cmake --build .
```

The resulting binary `brainfuck_interpreter` will be generated directly inside your local `build/` directory.

##  Testing & Execution

The repository includes an `examples/` directory containing iconic community scripts to verify the interpreter's functionality:

From the root directory of the project, you can run them using your compiled binary:

```bash
# 1. Basic Text Output Test (Hello World)
./build/brainfuck_interpreter examples/01_hello_world.bf

# 2. Algorithm & Stack Test (Sierpinski Triangle Generator)
./build/brainfuck_interpreter examples/sierpinski.bf

# 3. Interactive Math (Arbitrary Large Integer Factorizer)
./build/brainfuck_interpreter examples/factor.bf
```

##  License & Attributions

This interpreter core engine is open-source software licensed under the permissive **[MIT License](LICENSE)**. 

The testing scripts located within the `examples/` folder remain the property of their respective authors and the wider Brainfuck esolang open-source community.
