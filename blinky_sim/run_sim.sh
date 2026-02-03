#!/bin/bash

# 1. Environment Setup
export SDKROOT=$(xcrun --show-sdk-path)
cd "$(dirname "$0")/.."
mkdir -p sim

# 2. Compile
verilator -Wall --trace --cc src/blinky.sv --exe tb/tb_blinky.cpp \
          --Mdir sim \
          -o Vblinky_sim \
          --compiler clang \
          -CFLAGS "-isysroot ${SDKROOT} -isystem ${SDKROOT}/usr/include/c++/v1"

# 3. Build the binary
make -C sim -f Vblinky.mk

# 4. Run the simulation and FORCE output
if [ -f "./sim/Vblinky_sim" ]; then
    echo "Running simulation binary..."
    ./sim/Vblinky_sim
    
    # Wait 1 second for macOS file system to catch up
    sleep 1
    
    if [ -f "sim/waveform.vcd" ]; then
        echo "SUCCESS: waveform.vcd created."
        ls -l sim/waveform.vcd
    else
        echo "ERROR: Simulation ran but waveform.vcd was NOT created."
    fi
else
    echo "ERROR: Build failed. Vblinky_sim not found."
fi