// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinky.h for the primary calling header

#include "Vblinky__pch.h"

void Vblinky___024root___ctor_var_reset(Vblinky___024root* vlSelf);

Vblinky___024root::Vblinky___024root(Vblinky__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vblinky___024root___ctor_var_reset(this);
}

void Vblinky___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vblinky___024root::~Vblinky___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
