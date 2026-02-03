// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_accelerator.h for the primary calling header

#include "Vtop_accelerator__pch.h"

void Vtop_accelerator___024root___ctor_var_reset(Vtop_accelerator___024root* vlSelf);

Vtop_accelerator___024root::Vtop_accelerator___024root(Vtop_accelerator__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop_accelerator___024root___ctor_var_reset(this);
}

void Vtop_accelerator___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop_accelerator___024root::~Vtop_accelerator___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
