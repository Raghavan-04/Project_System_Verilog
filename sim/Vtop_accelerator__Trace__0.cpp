// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop_accelerator__Syms.h"


void Vtop_accelerator___024root__trace_chg_0_sub_0(Vtop_accelerator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_accelerator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_chg_0\n"); );
    // Body
    Vtop_accelerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_accelerator___024root*>(voidSelf);
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop_accelerator___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_accelerator___024root__trace_chg_0_sub_0(Vtop_accelerator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_chg_0_sub_0\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgSData(oldp+0,(vlSelfRef.top_accelerator__DOT__fifo_a_out),16);
        bufp->chgSData(oldp+1,(vlSelfRef.top_accelerator__DOT__fifo_b_out),16);
        bufp->chgBit(oldp+2,(vlSelfRef.top_accelerator__DOT__fifo_empty));
        bufp->chgBit(oldp+3,((1U & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_empty)))));
        bufp->chgCData(oldp+4,(vlSelfRef.top_accelerator__DOT__valid_pipe),2);
        bufp->chgSData(oldp+5,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[0]),16);
        bufp->chgSData(oldp+6,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[1]),16);
        bufp->chgSData(oldp+7,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[2]),16);
        bufp->chgSData(oldp+8,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[3]),16);
        bufp->chgSData(oldp+9,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[4]),16);
        bufp->chgSData(oldp+10,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[5]),16);
        bufp->chgSData(oldp+11,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[6]),16);
        bufp->chgSData(oldp+12,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[7]),16);
        bufp->chgSData(oldp+13,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[8]),16);
        bufp->chgSData(oldp+14,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[9]),16);
        bufp->chgSData(oldp+15,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[10]),16);
        bufp->chgSData(oldp+16,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[11]),16);
        bufp->chgSData(oldp+17,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[12]),16);
        bufp->chgSData(oldp+18,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[13]),16);
        bufp->chgSData(oldp+19,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[14]),16);
        bufp->chgSData(oldp+20,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[15]),16);
        bufp->chgCData(oldp+21,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr),5);
        bufp->chgCData(oldp+22,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr),5);
        bufp->chgBit(oldp+23,((((1U & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr) 
                                       >> 4U)) != (1U 
                                                   & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr) 
                                                      >> 4U))) 
                               & ((0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr)) 
                                  == (0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr))))));
        bufp->chgBit(oldp+24,(((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr) 
                               == (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr))));
        bufp->chgSData(oldp+25,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[0]),16);
        bufp->chgSData(oldp+26,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[1]),16);
        bufp->chgSData(oldp+27,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[2]),16);
        bufp->chgSData(oldp+28,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[3]),16);
        bufp->chgSData(oldp+29,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[4]),16);
        bufp->chgSData(oldp+30,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[5]),16);
        bufp->chgSData(oldp+31,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[6]),16);
        bufp->chgSData(oldp+32,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[7]),16);
        bufp->chgSData(oldp+33,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[8]),16);
        bufp->chgSData(oldp+34,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[9]),16);
        bufp->chgSData(oldp+35,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[10]),16);
        bufp->chgSData(oldp+36,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[11]),16);
        bufp->chgSData(oldp+37,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[12]),16);
        bufp->chgSData(oldp+38,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[13]),16);
        bufp->chgSData(oldp+39,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[14]),16);
        bufp->chgSData(oldp+40,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[15]),16);
        bufp->chgCData(oldp+41,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr),5);
        bufp->chgCData(oldp+42,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr),5);
        bufp->chgIData(oldp+43,(vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg),32);
        bufp->chgIData(oldp+44,(vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg),32);
        bufp->chgIData(oldp+45,(vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc),32);
    }
    bufp->chgBit(oldp+46,(vlSelfRef.clk));
    bufp->chgBit(oldp+47,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+48,(vlSelfRef.wr_en));
    bufp->chgSData(oldp+49,(vlSelfRef.din_a),16);
    bufp->chgSData(oldp+50,(vlSelfRef.din_b),16);
    bufp->chgBit(oldp+51,(vlSelfRef.fifo_full));
    bufp->chgBit(oldp+52,(vlSelfRef.acc_clr));
    bufp->chgIData(oldp+53,(vlSelfRef.acc_out),32);
    bufp->chgBit(oldp+54,(vlSelfRef.valid_out));
}

void Vtop_accelerator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_cleanup\n"); );
    // Body
    Vtop_accelerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_accelerator___024root*>(voidSelf);
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
