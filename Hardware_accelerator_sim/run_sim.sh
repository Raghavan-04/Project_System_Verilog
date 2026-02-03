#!/bin/bash

# 1. Environment Setup
export SDKROOT=$(xcrun --show-sdk-path)
cd "$(dirname "$0")/.."
mkdir -p sim

# 2. Compile
# Update the Compile section in run_sim.sh
verilator -Wall -Wno-EOFNEWLINE -Wno-PINCONNECTEMPTY --trace --cc \
          src/top_accelerator.sv \
          -Isrc \
          --exe tb/tb_top.cpp \
          --Mdir sim \
          -o Vaccelerator_sim \
          --compiler clang \
          -CFLAGS "-isysroot ${SDKROOT} -isystem ${SDKROOT}/usr/include/c++/v1"

# 3. Build the binary
make -C sim -f Vtop_accelerator.mk

# 4. Run the simulation and FORCE output
if [ -f "./sim/Vaccelerator_sim" ]; then
    echo "Running simulation binary..."
    ./sim/Vaccelerator_sim
    
    # Wait 1 second for macOS file system to catch up
    sleep 1
    
    if [ -f "sim/waveform.vcd" ]; then
        echo "SUCCESS: waveform.vcd created."
        ls -l sim/waveform.vcd
    else
        echo "ERROR: Simulation ran but waveform.vcd was NOT created."
    fi
else
    echo "ERROR: Build failed. Vtop_accelerator_sim not found."
fi