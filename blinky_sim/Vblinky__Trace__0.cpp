// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vblinky__Syms.h"


void Vblinky___024root__trace_chg_0_sub_0(Vblinky___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vblinky___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_chg_0\n"); );
    // Body
    Vblinky___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinky___024root*>(voidSelf);
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vblinky___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vblinky___024root__trace_chg_0_sub_0(Vblinky___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_chg_0_sub_0\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst));
    bufp->chgBit(oldp+2,(vlSelfRef.led));
    bufp->chgCData(oldp+3,(vlSelfRef.blinky__DOT__count),4);
}

void Vblinky___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vblinky___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinky___024root*>(voidSelf);
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
