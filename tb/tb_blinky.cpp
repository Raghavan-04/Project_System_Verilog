#include <iostream>          // Needed for printing status messages
#include <verilated.h>       // Core Verilator library
#include <verilated_vcd_c.h> // Needed to record waveforms (.vcd)
#include "Vblinky.h"        // This header is created by Verilator during build

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vblinky* top = new Vblinky; // Create an instance of our hardware

    // Setup waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("sim/waveform.vcd"); // Save results in the sim folder

    int time = 0;
    top->rst = 1; top->clk = 0; // Start with Reset active

    while (time < 100) {
        if (time > 10) top->rst = 0; // Release Reset after 10 time units
        top->clk = !top->clk;        // Toggle the clock signal
        top->eval();                 // Evaluate the hardware logic
        tfp->dump(time);             // Record the current signal states
        time++;
    }

    tfp->close();
    delete top;
    std::cout << "Simulation complete! Waveform saved to sim/waveform.vcd" << std::endl;
    return 0;
}