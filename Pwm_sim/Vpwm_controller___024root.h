// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vpwm_controller.h for the primary calling header

#ifndef VERILATED_VPWM_CONTROLLER___024ROOT_H_
#define VERILATED_VPWM_CONTROLLER___024ROOT_H_  // guard

#include "verilated.h"


class Vpwm_controller__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vpwm_controller___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(duty_cycle,7,0);
    VL_OUT8(pwm_out,0,0);
    CData/*7:0*/ pwm_controller__DOT__counter;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vpwm_controller__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vpwm_controller___024root(Vpwm_controller__Syms* symsp, const char* namep);
    ~Vpwm_controller___024root();
    VL_UNCOPYABLE(Vpwm_controller___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
