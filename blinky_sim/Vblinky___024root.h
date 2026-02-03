// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vblinky.h for the primary calling header

#ifndef VERILATED_VBLINKY___024ROOT_H_
#define VERILATED_VBLINKY___024ROOT_H_  // guard

#include "verilated.h"


class Vblinky__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vblinky___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(led,0,0);
    CData/*3:0*/ blinky__DOT__count;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vblinky__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vblinky___024root(Vblinky__Syms* symsp, const char* namep);
    ~Vblinky___024root();
    VL_UNCOPYABLE(Vblinky___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
