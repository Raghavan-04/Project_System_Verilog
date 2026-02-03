

### 1. The Entry Point (The Data Burst)

When your C++ testbench starts, it acts as the "Host." It checks the `fifo_full` signal. If the signal is low, it pulses `wr_en` and places data on `din_a` and `din_b`.

* **Action:** Data enters the two Synchronous FIFOs simultaneously.
* **Result:** The `fifo_empty` signal inside the top module immediately drops to **low**.

### 2. The Trigger (Auto-Enable)

The system is "self-starting." We have a logic line inside the code: `assign mac_en = !fifo_empty;`.

* As soon as that first piece of data lands in the FIFO, the `mac_en` signal goes high.
* This tells the FIFOs to start outputting data on `dout` and tells the MAC unit to wake up.

### 3. The assembly line (The Pipeline)

This is where the math happens in two distinct stages. Imagine two people standing at a conveyor belt:

* **Cycle N:** The FIFO outputs values (e.g.,  and ). The **Multiplier** inside the MAC unit calculates  and stores it in `mult_reg`.
* **Cycle N+1:** While the Multiplier is busy calculating the *next* pair (), the **Accumulator** takes that  from the previous cycle and adds it to the running total.

### 4. Backpressure Management

If the testbench sends data faster than the MAC can process it, the FIFOs fill up.

* Once the 16 slots are full, the `fifo_full` signal goes high.
* The testbench (Host) sees this and **pauses** sending data, preventing any loss or corruption.

### 5. Validating the Result

Because of the 2-cycle latency in the MAC, the output `acc_out` isn't valid immediately.

* We have a **delay line** (a 2-bit shift register) that tracks the `mac_en` signal.
* After 2 cycles, the `valid_out` signal goes high at the exact moment the completed sum reaches the output pins.

---

### 📊 Summary of the State Machine Flow

| State | Action | Pointer Status |
| --- | --- | --- |
| **Idle** | Waiting for Host. | `wr_ptr == rd_ptr` |
| **Buffering** | Host writing to FIFOs; MAC starting up. | `wr_ptr > rd_ptr` |
| **Processing** | MAC drinking from FIFO; totalizing sum. | `rd_ptr` chasing `wr_ptr` |
| **Draining** | Host stopped writing; MAC finishing last bits. | `rd_ptr` catches up |

---

### 🛠️ Final Build Check

To make this work on your MacBook, ensure your `scripts/run_sim.sh` includes all three `.sv` files so Verilator can link them:

```bash
# Update the compile command to include all source files
verilator -Wall -Wno-EOFNEWLINE --trace --cc \
          src/sync_fifo.sv \
          src/mac_unit.sv \
          src/top_accelerator.sv \
          --exe tb/tb_top.cpp \
          --Mdir sim -o Vaccelerator_sim \
          --compiler clang \
          -CFLAGS "-isysroot ${SDKROOT} -isystem ${SDKROOT}/usr/include/c++/v1"

make -C sim -f Vaccelerator_sim.mk
./sim/Vaccelerator_sim

```


## 🚀 Architecture Overview
- **Data Path:** Dual 16-bit inputs (Q8.8 compatible) with a 32-bit output.
- **Buffer:** 16-deep Synchronous FIFOs for seamless data streaming.
- **Logic:** 2-stage pipelined MAC with built-in **Signed Saturation Logic** to prevent arithmetic wrap-around.
- **Flow Control:** Integrated valid/ready-style handshaking and backpressure support.



## 🛠️ Design Structure
- `src/mac_unit.sv`: The arithmetic core with pipeline stages and saturation logic.
- `src/sync_fifo.sv`: Pointer-based circular buffer for data management.
- `src/top_accelerator.sv`: Top-level integration and pipeline signal alignment.
- `tb/tb_top.cpp`: C++ testbench for performance verification.

## 💻 How to Run (macOS)
Ensure you have **Verilator** and **GTKWave** installed via Homebrew.

1. **Compile & Simulate:**
   ```bash
   chmod +x scripts/run_sim.sh
   ./scripts/run_sim.sh