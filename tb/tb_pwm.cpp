#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vpwm_controller.h"
#include <iostream>
#include <sys/stat.h>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vpwm_controller* top = new Vpwm_controller;

    // 1. Initialize Trace
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    
    // 2. Open file and verify it opens
    std::cout << "Opening waveform.vcd..." << std::endl;
    tfp->open("sim/waveform.vcd");

    int time = 0;
    top->rst_n = 0;
    top->duty_cycle = 128; // 50% duty cycle for clear visibility

    // 3. Simulation Loop
    while (time < 5000) {
        if (time > 50) top->rst_n = 1;
        
        top->clk = !top->clk; 
        top->eval();
        tfp->dump(time); // This writes the data
        time++;
    }

    // 4. Critical: Flush and Close
    tfp->flush(); 
    tfp->close();
    std::cout << "Simulation complete. Waveform should be at sim/waveform.vcd" << std::endl;
    
    delete top;
    return 0;
}