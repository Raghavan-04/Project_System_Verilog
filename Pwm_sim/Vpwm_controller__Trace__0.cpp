// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vpwm_controller__Syms.h"


void Vpwm_controller___024root__trace_chg_0_sub_0(Vpwm_controller___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vpwm_controller___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_controller___024root__trace_chg_0\n"); );
    // Body
    Vpwm_controller___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_controller___024root*>(voidSelf);
    Vpwm_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vpwm_controller___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vpwm_controller___024root__trace_chg_0_sub_0(Vpwm_controller___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_controller___024root__trace_chg_0_sub_0\n"); );
    Vpwm_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+2,(vlSelfRef.duty_cycle),8);
    bufp->chgBit(oldp+3,(vlSelfRef.pwm_out));
    bufp->chgCData(oldp+4,(vlSelfRef.pwm_controller__DOT__counter),8);
}

void Vpwm_controller___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vpwm_controller___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vpwm_controller___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_controller___024root*>(voidSelf);
    Vpwm_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
