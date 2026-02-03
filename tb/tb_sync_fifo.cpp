#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vsync_fifo.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vsync_fifo* dut = new Vsync_fifo;

    // Trace setup
    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("sim/waveform.vcd");

    int time = 0;
    auto tick = [&]() {
        dut->clk = 0; dut->eval(); m_trace->dump(time++);
        dut->clk = 1; dut->eval(); m_trace->dump(time++);
    };

    // 1. Reset
    dut->rst_n = 0;
    dut->wr_en = 0;
    dut->rd_en = 0;
    tick();
    dut->rst_n = 1;
    tick();

    // 2. Test: Write until Full
    std::cout << "Writing to FIFO..." << std::endl;
    for (int i = 0; i < 8; i++) {
        if (!dut->full) {
            dut->wr_en = 1;
            dut->din = 100 + i; // Data: 100, 101, 102...
            tick();
        }
    }
    dut->wr_en = 0;
    tick();

    if (dut->full) std::cout << "FIFO is successfully FULL." << std::endl;

    // 3. Test: Read until Empty
    std::cout << "Reading from FIFO..." << std::endl;
    for (int i = 0; i < 8; i++) {
        if (!dut->empty) {
            dut->rd_en = 1;
            tick();
            std::cout << "Read Data: " << (int)dut->dout << std::endl;
        }
    }
    dut->rd_en = 0;
    tick();

    if (dut->empty) std::cout << "FIFO is successfully EMPTY." << std::endl;

    m_trace->close();
    delete dut;
    return 0;
}