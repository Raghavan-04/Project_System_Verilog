// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vsync_fifo__Syms.h"


void Vsync_fifo___024root__trace_chg_0_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vsync_fifo___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_chg_0\n"); );
    // Body
    Vsync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsync_fifo___024root*>(voidSelf);
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vsync_fifo___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vsync_fifo___024root__trace_chg_0_sub_0(Vsync_fifo___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_chg_0_sub_0\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.sync_fifo__DOT__mem[0]),16);
        bufp->chgSData(oldp+1,(vlSelfRef.sync_fifo__DOT__mem[1]),16);
        bufp->chgSData(oldp+2,(vlSelfRef.sync_fifo__DOT__mem[2]),16);
        bufp->chgSData(oldp+3,(vlSelfRef.sync_fifo__DOT__mem[3]),16);
        bufp->chgSData(oldp+4,(vlSelfRef.sync_fifo__DOT__mem[4]),16);
        bufp->chgSData(oldp+5,(vlSelfRef.sync_fifo__DOT__mem[5]),16);
        bufp->chgSData(oldp+6,(vlSelfRef.sync_fifo__DOT__mem[6]),16);
        bufp->chgSData(oldp+7,(vlSelfRef.sync_fifo__DOT__mem[7]),16);
        bufp->chgCData(oldp+8,(vlSelfRef.sync_fifo__DOT__wr_ptr),4);
        bufp->chgCData(oldp+9,(vlSelfRef.sync_fifo__DOT__rd_ptr),4);
    }
    bufp->chgBit(oldp+10,(vlSelfRef.clk));
    bufp->chgBit(oldp+11,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+12,(vlSelfRef.wr_en));
    bufp->chgSData(oldp+13,(vlSelfRef.din),16);
    bufp->chgBit(oldp+14,(vlSelfRef.full));
    bufp->chgBit(oldp+15,(vlSelfRef.rd_en));
    bufp->chgSData(oldp+16,(vlSelfRef.dout),16);
    bufp->chgBit(oldp+17,(vlSelfRef.empty));
}

void Vsync_fifo___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root__trace_cleanup\n"); );
    // Body
    Vsync_fifo___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vsync_fifo___024root*>(voidSelf);
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
