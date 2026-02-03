// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac_unit.h for the primary calling header

#include "Vmac_unit__pch.h"

void Vmac_unit___024root___ctor_var_reset(Vmac_unit___024root* vlSelf);

Vmac_unit___024root::Vmac_unit___024root(Vmac_unit__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vmac_unit___024root___ctor_var_reset(this);
}

void Vmac_unit___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmac_unit___024root::~Vmac_unit___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
