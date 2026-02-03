#!/bin/bash

# 1. Environment Setup
export SDKROOT=$(xcrun --show-sdk-path)
cd "$(dirname "$0")/.."
mkdir -p sim

# 2. Compile
verilator -Wall --trace --cc src/pwm_controller.sv --exe tb/tb_pwm.cpp \
          --Mdir sim \
          -o Vpwm_controller_sim \
          --compiler clang \
          -CFLAGS "-isysroot ${SDKROOT} -isystem ${SDKROOT}/usr/include/c++/v1"

# 3. Build the binary
make -C sim -f Vpwm_controller.mk

# 4. Run the simulation and FORCE output
if [ -f "./sim/Vpwm_controller_sim" ]; then
    echo "Running simulation binary..."
    ./sim/Vpwm_controller_sim
    
    # Wait 1 second for macOS file system to catch up
    sleep 1
    
    if [ -f "sim/waveform.vcd" ]; then
        echo "SUCCESS: waveform.vcd created."
        ls -l sim/waveform.vcd
    else
        echo "ERROR: Simulation ran but waveform.vcd was NOT created."
    fi
else
    echo "ERROR: Build failed. Vpwm_controller_sim not found."
fi