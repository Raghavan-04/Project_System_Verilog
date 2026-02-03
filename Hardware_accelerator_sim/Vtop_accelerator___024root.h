// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_accelerator.h for the primary calling header

#ifndef VERILATED_VTOP_ACCELERATOR___024ROOT_H_
#define VERILATED_VTOP_ACCELERATOR___024ROOT_H_  // guard

#include "verilated.h"


class Vtop_accelerator__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_accelerator___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(wr_en,0,0);
    VL_OUT8(fifo_full,0,0);
    VL_IN8(acc_clr,0,0);
    VL_OUT8(valid_out,0,0);
    CData/*0:0*/ top_accelerator__DOT__fifo_empty;
    CData/*1:0*/ top_accelerator__DOT__valid_pipe;
    CData/*4:0*/ top_accelerator__DOT__fifo_a__DOT__wr_ptr;
    CData/*4:0*/ top_accelerator__DOT__fifo_a__DOT__rd_ptr;
    CData/*0:0*/ top_accelerator__DOT__fifo_b__DOT__full;
    CData/*0:0*/ top_accelerator__DOT__fifo_b__DOT__empty;
    CData/*4:0*/ top_accelerator__DOT__fifo_b__DOT__wr_ptr;
    CData/*4:0*/ top_accelerator__DOT__fifo_b__DOT__rd_ptr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    VL_IN16(din_a,15,0);
    VL_IN16(din_b,15,0);
    SData/*15:0*/ top_accelerator__DOT__fifo_a_out;
    SData/*15:0*/ top_accelerator__DOT__fifo_b_out;
    VL_OUT(acc_out,31,0);
    IData/*31:0*/ top_accelerator__DOT__processor__DOT__mult_reg;
    IData/*31:0*/ top_accelerator__DOT__processor__DOT__acc_reg;
    IData/*31:0*/ top_accelerator__DOT__processor__DOT__next_acc;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 16> top_accelerator__DOT__fifo_a__DOT__mem;
    VlUnpacked<SData/*15:0*/, 16> top_accelerator__DOT__fifo_b__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop_accelerator__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_accelerator___024root(Vtop_accelerator__Syms* symsp, const char* namep);
    ~Vtop_accelerator___024root();
    VL_UNCOPYABLE(Vtop_accelerator___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
