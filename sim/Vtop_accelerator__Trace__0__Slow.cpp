// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop_accelerator__Syms.h"


VL_ATTR_COLD void Vtop_accelerator___024root__trace_init_sub__TOP__0(Vtop_accelerator___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_init_sub__TOP__0\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    tracep->pushPrefix("$rootio", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"din_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+51,0,"din_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+52,0,"fifo_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"acc_clr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+55,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("top_accelerator", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+56,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"din_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+51,0,"din_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+52,0,"fifo_full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"acc_clr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+54,0,"acc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+55,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"fifo_a_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+2,0,"fifo_b_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+3,0,"fifo_empty",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"mac_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"valid_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("fifo_a", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+56,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+50,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+52,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+3,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+6+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+22,0,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+23,0,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("fifo_b", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+56,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+56,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"ADDR_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+24,0,"full",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"dout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+25,0,"empty",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("mem", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+26+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+42,0,"wr_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+43,0,"rd_ptr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("processor", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+56,0,"WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+47,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+4,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+53,0,"clr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+1,0,"a_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+2,0,"b_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+54,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"mult_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"acc_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"next_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"MAX_POS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+59,0,"MAX_NEG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop_accelerator___024root__trace_init_top(Vtop_accelerator___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_init_top\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_accelerator___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop_accelerator___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop_accelerator___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_accelerator___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_accelerator___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop_accelerator___024root__trace_register(Vtop_accelerator___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_register\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop_accelerator___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop_accelerator___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop_accelerator___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop_accelerator___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop_accelerator___024root__trace_const_0_sub_0(Vtop_accelerator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_accelerator___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_const_0\n"); );
    // Body
    Vtop_accelerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_accelerator___024root*>(voidSelf);
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop_accelerator___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_accelerator___024root__trace_const_0_sub_0(Vtop_accelerator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_const_0_sub_0\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+56,(0x00000010U),32);
    bufp->fullIData(oldp+57,(4U),32);
    bufp->fullIData(oldp+58,(0x7fffffffU),32);
    bufp->fullIData(oldp+59,(0x80000000U),32);
}

VL_ATTR_COLD void Vtop_accelerator___024root__trace_full_0_sub_0(Vtop_accelerator___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_accelerator___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_full_0\n"); );
    // Body
    Vtop_accelerator___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_accelerator___024root*>(voidSelf);
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop_accelerator___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_accelerator___024root__trace_full_0_sub_0(Vtop_accelerator___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root__trace_full_0_sub_0\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullSData(oldp+1,(vlSelfRef.top_accelerator__DOT__fifo_a_out),16);
    bufp->fullSData(oldp+2,(vlSelfRef.top_accelerator__DOT__fifo_b_out),16);
    bufp->fullBit(oldp+3,(vlSelfRef.top_accelerator__DOT__fifo_empty));
    bufp->fullBit(oldp+4,((1U & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_empty)))));
    bufp->fullCData(oldp+5,(vlSelfRef.top_accelerator__DOT__valid_pipe),2);
    bufp->fullSData(oldp+6,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[0]),16);
    bufp->fullSData(oldp+7,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[1]),16);
    bufp->fullSData(oldp+8,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[2]),16);
    bufp->fullSData(oldp+9,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[3]),16);
    bufp->fullSData(oldp+10,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[4]),16);
    bufp->fullSData(oldp+11,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[5]),16);
    bufp->fullSData(oldp+12,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[6]),16);
    bufp->fullSData(oldp+13,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[7]),16);
    bufp->fullSData(oldp+14,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[8]),16);
    bufp->fullSData(oldp+15,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[9]),16);
    bufp->fullSData(oldp+16,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[10]),16);
    bufp->fullSData(oldp+17,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[11]),16);
    bufp->fullSData(oldp+18,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[12]),16);
    bufp->fullSData(oldp+19,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[13]),16);
    bufp->fullSData(oldp+20,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[14]),16);
    bufp->fullSData(oldp+21,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[15]),16);
    bufp->fullCData(oldp+22,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr),5);
    bufp->fullCData(oldp+23,(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr),5);
    bufp->fullBit(oldp+24,((((1U & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr) 
                                    >> 4U)) != (1U 
                                                & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr) 
                                                   >> 4U))) 
                            & ((0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr)) 
                               == (0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr))))));
    bufp->fullBit(oldp+25,(((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr) 
                            == (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr))));
    bufp->fullSData(oldp+26,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[0]),16);
    bufp->fullSData(oldp+27,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[1]),16);
    bufp->fullSData(oldp+28,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[2]),16);
    bufp->fullSData(oldp+29,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[3]),16);
    bufp->fullSData(oldp+30,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[4]),16);
    bufp->fullSData(oldp+31,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[5]),16);
    bufp->fullSData(oldp+32,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[6]),16);
    bufp->fullSData(oldp+33,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[7]),16);
    bufp->fullSData(oldp+34,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[8]),16);
    bufp->fullSData(oldp+35,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[9]),16);
    bufp->fullSData(oldp+36,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[10]),16);
    bufp->fullSData(oldp+37,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[11]),16);
    bufp->fullSData(oldp+38,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[12]),16);
    bufp->fullSData(oldp+39,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[13]),16);
    bufp->fullSData(oldp+40,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[14]),16);
    bufp->fullSData(oldp+41,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[15]),16);
    bufp->fullCData(oldp+42,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr),5);
    bufp->fullCData(oldp+43,(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr),5);
    bufp->fullIData(oldp+44,(vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg),32);
    bufp->fullIData(oldp+45,(vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc),32);
    bufp->fullBit(oldp+47,(vlSelfRef.clk));
    bufp->fullBit(oldp+48,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+49,(vlSelfRef.wr_en));
    bufp->fullSData(oldp+50,(vlSelfRef.din_a),16);
    bufp->fullSData(oldp+51,(vlSelfRef.din_b),16);
    bufp->fullBit(oldp+52,(vlSelfRef.fifo_full));
    bufp->fullBit(oldp+53,(vlSelfRef.acc_clr));
    bufp->fullIData(oldp+54,(vlSelfRef.acc_out),32);
    bufp->fullBit(oldp+55,(vlSelfRef.valid_out));
}
