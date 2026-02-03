
# SystemVerilog Exploration

This repository serves as a personal laboratory for learning **SystemVerilog** through the lens of medical device hardware, specifically inspired by the real-time control requirements of a **ventilator**.

## 🛠 Project Overview

Rather than a single fixed application, this repository contains various modules designed to master different aspects of RTL (Register Transfer Level) design, from basic signal toggling to complex pulse modulation.

### Current Modules

* **Blinky**: The "Hello World" of hardware. This module uses a clock divider to toggle an LED (or signal) at a human-readable frequency, demonstrating basic sequential logic and counters.
* **PWM Controller**: A Pulse Width Modulation module used to simulate valve control. By adjusting the duty cycle, the module controls the "flow rate," mimicking how a ventilator regulates air pressure to a patient.
* **Mac Unit**: A Multiply-Accumulate (MAC) unit that takes two numbers, multiplies them, and adds them to a running total—all while using a pipeline to keep the clock speed high. We will use Fixed-Point Arithmetic (specifically Q8.8), which means we use 16 bits: 8 bits for the whole number and 8 bits for the fraction.
* **Synchrounous FIFO**:The Synchronous FIFO serves as a robust data buffer that ensures your high-speed MAC unit never "starves" for data or loses information during bursts.By using an extra bit in the write and read pointers, the logic effortlessly distinguishes between a completely empty buffer and a full one, even when the address indices are identical.
* **Hardware Accelerator**:A hardware accelerator featuring a 2-stage pipelined MAC unit, dual-stream synchronous FIFOs, and signed saturation logic for high-performance arithmetic. It manages backpressure via full/empty flags, making it an ideal foundation for more complex systems like Neural Networks or Digital Signal Processors.

---

## 🏗 Directory Structure

The repository is organized to separate the hardware description from the simulation and build artifacts:

* **`src/`**: The core SystemVerilog (.sv) source files.
* **`tb/`**: The C++ and SystemVerilog testbenches used to drive and verify the logic.
* **`scripts/`**: Automation tools for compiling and running simulations.
* **`sim/`**: A workspace for the compiler; contains the generated binaries and waveform files.

---

## 🚀 Simulation Environment

To ensure medical-grade reliability, this project uses a high-performance simulation stack:

1. **Linter/Simulator**: [Verilator](https://www.google.com/search?q=https://www.verilator.org/) (Converts SystemVerilog to high-speed C++).
2. **Test Driver**: C++ Wrapper (Handles clock generation and waveform dumping).
3. **Visualization**: [GTKWave](https://gtkwave.sourceforge.net/) or [Surfer](https://app.surfer-project.org/) for viewing `.vcd` waveform files.

### How to Run

Execute the following from the root directory to compile and run the current simulation:

```bash
./scripts/run_sim.sh

```

---

## 📈 Key Learnings


### 1. Advanced RTL Architecture

* **Pipelining:** I learned how to break complex math () into distinct stages using registers to increase the "speed limit" (clock frequency) of your chip.
* **The MAC Unit:** I built a Multiply-Accumulate unit, the "beating heart" of almost all hardware accelerators (DSPs, TPUs, and GPUs).
* **Dataflow Design:** I moved from static logic to a "streaming" architecture where data flows through the system like water through a pipe.

### 2. Digital Arithmetic & Robustness

* **Fixed-Point Math:** I explored how to handle decimals in hardware without using expensive Floating Point Units.
* **Signed Logic:** I used Two's Complement arithmetic to handle positive and negative numbers correctly.
* **Saturation Logic:** I implemented "clipping" hardware to prevent the "wrap-around" bug, ensuring that if a number gets too big, it stays at the maximum value instead of glitching.

### 3. Memory & Flow Control

* **Synchronous FIFOs:** I built a circular buffer to act as a "waiting room" for data.
* **The "Extra Bit" Trick:** I learned how to use an  bit pointer to perfectly distinguish between a "Full" and "Empty" buffer.
* **Backpressure:** I implemented status flags (`full`/`empty`) to tell the "Host" (your Mac) when to stop sending data.

### 4. Professional Verification Flow

* **Modular Integration:** I learned how to wrap multiple sub-modules (`mac_unit` and `sync_fifo`) into a single `top_accelerator` module.
* **Verilator Multi-File Build:** I mastered the `-I` include flags and `-Wno` linting flags to compile complex, multi-file projects on macOS.
* **C++ Hardware Modeling:** I wrote a sophisticated testbench to "burst" data into your hardware and monitor the pipeline latency.

---
## 📈 Challenges


### 1. The "Structural" Challenge: Hierarchical Design

Earlier, I wrote everything in one file. Today, you had to learn **top-down architecture**.

* **The Struggle:** Connecting wires between a FIFO and a MAC while managing parameters like `WIDTH` and `DEPTH`.
* **The Lesson:** You learned how to instantiate sub-modules and use a **Top-Level Wrapper** to organize complex logic.

### 2. The "Mathematical" Challenge: Bit-Width & Overflow

Arithmetic in hardware is "expensive" and dangerous.

* **The Struggle:** Dealing with the fact that , and the potential for "wrap-around" bugs.
* **The Lesson:** I implemented **Saturation Logic**. You moved from "simple math" to "robust math" that won't crash when numbers get too high.

### 3. The "Tooling" Challenge: Verilator's Strictness

Verilator is a "linting" simulator, meaning it is much stricter than others.

* **The Struggle:** Dealing with `EOFNEWLINE` (missing newlines), `MODMISSING` (include paths), and naming mismatches between Verilog and C++.
* **The Lesson:** You mastered the **Verilator Build Flow** on macOS, learning how to use `-I` flags and handle Makefiles.

### 4. The "Temporal" Challenge: Pipeline Latency

This is the hardest shift for software developers.

* **The Struggle:** Realizing that the data you put into the FIFO at "Time 0" doesn't appear at the output until "Time 3."
* **The Lesson:** You built a **Valid Delay Line** (Shift Register) to align your status signals with your data.

### 5. The "Communication" Challenge: Backpressure

* **The Struggle:** Preventing the "Host" ( Mac) from overwhelming the hardware.
* **The Lesson:** You implemented **FIFO Status Flags** (`full`/`empty`) to create a hardware-level "handshake."

---

### 🔍 My Current : The 200 Bug

Seeing "200" instead of "700" is actually most important challenge yet. It represents a **Timing Race Condition**.

* **What it is:**  Testbench is likely "sampling" the output before it’s ready, or FIFO is reading too fast/slow.
* **Why it's good:** Debugging this in **GTKWave** is exactly what RTL engineers do for 80% of their workday.
* **Sequential vs. Combinational Logic**: Using `always_ff` for clocked memory and `always_comb` for immediate logic gates.
* **Clock Management**: Implementing counters to divide high-frequency system clocks into usable timing intervals.
* **Verification**: Writing C++ testbenches to "force-flush" waveform data to disk for analysis.

---

## 🔭 Future Explorations

* Implementing **Finite State Machines (FSM)** for breath cycle management (Inspiration vs. Expiration).
* Building **Serial Interfaces** (SPI/I2C) to simulate reading from airway pressure sensors.
* Applying **Assertions** to ensure safety limits (e.g., preventing over-pressurization).

---

