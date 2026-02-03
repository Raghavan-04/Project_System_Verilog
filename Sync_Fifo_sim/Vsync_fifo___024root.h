// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsync_fifo.h for the primary calling header

#ifndef VERILATED_VSYNC_FIFO___024ROOT_H_
#define VERILATED_VSYNC_FIFO___024ROOT_H_  // guard

#include "verilated.h"


class Vsync_fifo__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsync_fifo___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(wr_en,0,0);
    VL_OUT8(full,0,0);
    VL_IN8(rd_en,0,0);
    VL_OUT8(empty,0,0);
    CData/*3:0*/ sync_fifo__DOT__wr_ptr;
    CData/*3:0*/ sync_fifo__DOT__rd_ptr;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    VL_IN16(din,15,0);
    VL_OUT16(dout,15,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 8> sync_fifo__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vsync_fifo__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vsync_fifo___024root(Vsync_fifo__Syms* symsp, const char* namep);
    ~Vsync_fifo___024root();
    VL_UNCOPYABLE(Vsync_fifo___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
