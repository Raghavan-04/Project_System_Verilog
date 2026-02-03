// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vmac_unit__Syms.h"


void Vmac_unit___024root__trace_chg_0_sub_0(Vmac_unit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vmac_unit___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root__trace_chg_0\n"); );
    // Body
    Vmac_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac_unit___024root*>(voidSelf);
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vmac_unit___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vmac_unit___024root__trace_chg_0_sub_0(Vmac_unit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root__trace_chg_0_sub_0\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.en));
    bufp->chgBit(oldp+3,(vlSelfRef.clr));
    bufp->chgSData(oldp+4,(vlSelfRef.a_in),16);
    bufp->chgSData(oldp+5,(vlSelfRef.b_in),16);
    bufp->chgIData(oldp+6,(vlSelfRef.out),32);
    bufp->chgIData(oldp+7,(vlSelfRef.mac_unit__DOT__mult_reg),32);
    bufp->chgIData(oldp+8,(vlSelfRef.mac_unit__DOT__acc_reg),32);
}

void Vmac_unit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vmac_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac_unit___024root*>(voidSelf);
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
