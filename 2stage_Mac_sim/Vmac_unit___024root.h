// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmac_unit.h for the primary calling header

#ifndef VERILATED_VMAC_UNIT___024ROOT_H_
#define VERILATED_VMAC_UNIT___024ROOT_H_  // guard

#include "verilated.h"


class Vmac_unit__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmac_unit___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(en,0,0);
    VL_IN8(clr,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    VL_IN16(a_in,15,0);
    VL_IN16(b_in,15,0);
    VL_OUT(out,31,0);
    IData/*31:0*/ mac_unit__DOT__mult_reg;
    IData/*31:0*/ mac_unit__DOT__acc_reg;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmac_unit__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmac_unit___024root(Vmac_unit__Syms* symsp, const char* namep);
    ~Vmac_unit___024root();
    VL_UNCOPYABLE(Vmac_unit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
