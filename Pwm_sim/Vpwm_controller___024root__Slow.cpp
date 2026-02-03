// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vpwm_controller.h for the primary calling header

#include "Vpwm_controller__pch.h"

void Vpwm_controller___024root___ctor_var_reset(Vpwm_controller___024root* vlSelf);

Vpwm_controller___024root::Vpwm_controller___024root(Vpwm_controller__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vpwm_controller___024root___ctor_var_reset(this);
}

void Vpwm_controller___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vpwm_controller___024root::~Vpwm_controller___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
