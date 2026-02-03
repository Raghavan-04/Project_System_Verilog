To make this "pipelined," we break the operation into two distinct stages separated by flip-flops (registers).
Stage 1: Multiplication of inputs A and B.
Stage 2: Addition of the product to the current accumulator value.

1. Bit-Width Growth
Notice that the output out and acc_reg are 32 bits (WIDTH*2), while the inputs are 16 bits.

Why? When you multiply two 16-bit numbers, the result can be up to 32 bits long. If you don't grow the bit-width, you will "overflow" and get incorrect math.

2. The "Pipeline Latency"
Because there are two stages of registers, your first valid result will appear 2 clock cycles after you provide the first inputs.
Cycle 1: A×B is calculated and stored in mult_reg.
Cycle 2: mult_reg is added to acc_reg.
Cycle 3: The result is visible at out.
3. Signed Logic
We use logic signed. This tells SystemVerilog to treat the most significant bit (MSB) as a plus/minus sign (Two's Complement). This is critical for real-world accelerators that handle negative weights or sensor data.

Clock Cycle,"Inputs (A,B)",Multiplier Reg (mult_reg),Accumulator Reg (acc_reg),Output (out)
T0,"2,3",0,0,0
T1,"4,5",6 (2×3),0,0
T2,"0,0",20 (4×5),6 (0+6),6
T3,Idle,0,26 (6+20),26


Observations
Latency: Note that even though we gave the first input at T0, the first part of the answer (6) didn't hit the output until T2.
Throughput: Once the pipeline is "full" (starting at T1), you are providing a new set of numbers every cycle, and the hardware is performing a multiplication and an addition simultaneously.
Bit Growth: If you are using Q8.8 format:
Input 2 is actually stored as 2×2^8=512.
Input 3 is 3×2^8=768.
The mult_reg will hold 512×768=393,216.
To read this as a normal number again, you would shift it back down (divide by 2^16 for multiplication or 2^8 for addition depending on your final formatting choice).
🛠️ How to see this in Verilator
When you run your simulation and open the waveform.vcd in GTKWave, you will see the mult_reg and acc_reg signals stepping forward like a staircase.


This is a great moment to zoom out. You've moved from a simple "blinky-style" PWM to designing a Pipelined MAC with Saturation, which is essentially the "beating heart" of any modern AI or Signal Processing chip.

Here is your textual roadmap. It tracks your journey from a beginner hardware learner to an architect of a custom Hardware Accelerator.

🗺️ The Hardware Architect's Roadmap
📍 Phase 1: The Foundation (Completed)
The Start: Basic Verilog syntax, understanding Modules, and Ports.
Key Milestone: The PWM Controller. You learned how to use a counter to create a variable digital signal.
The Tools: You mastered the MacBook-to-Verilator workflow, run_sim.sh scripting, and Git version control.
🚀 Phase 2: The Logic Engine (Current State)
Where you are now: Single Pipelined MAC Unit.
What you just built: You moved beyond "if/else" logic into Arithmetic Pipelines. You’ve implemented:
Signed Math: Handling negative numbers.
Pipelining: Breaking math into stages for higher clock speeds.
Saturation: Protecting the system from overflow bugs.
The Skill: You are now thinking about Latency (cycles) and Throughput (data per second).
⛓️ Phase 3: The Dataflow (Next Steps)
Goal: Moving from a "Unit" to a "System."
Focus: Buffers and Flow Control.
Upcoming Tasks:
FIFOs: Building a "waiting room" for data so the MAC stays busy.
Handshaking: Implementing Ready and Valid signals (The AXI-Stream standard).
Memory Interfaces: Reading data from a virtual SRAM instead of just testbench inputs.
🏁 Phase 4: The Accelerator (The Destination)
The End: A Multi-Core Systolic Array or Convolution Engine.
What it looks like: A grid of your MAC units working together to process an entire image or a large matrix in one "burst."
Final Milestone: Integrating your accelerator with a small RISC-V processor (SoC) where the CPU gives orders and your hardware does the heavy lifting.