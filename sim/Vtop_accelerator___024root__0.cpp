// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_accelerator.h for the primary calling header

#include "Vtop_accelerator__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_accelerator___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop_accelerator___024root___eval_triggers__act(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_triggers__act\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_accelerator___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vtop_accelerator___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop_accelerator___024root___nba_sequent__TOP__0(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___nba_sequent__TOP__0\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __VdlyVal__top_accelerator__DOT__fifo_a__DOT__mem__v0;
    __VdlyVal__top_accelerator__DOT__fifo_a__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__top_accelerator__DOT__fifo_a__DOT__mem__v0;
    __VdlyDim0__top_accelerator__DOT__fifo_a__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top_accelerator__DOT__fifo_a__DOT__mem__v0;
    __VdlySet__top_accelerator__DOT__fifo_a__DOT__mem__v0 = 0;
    SData/*15:0*/ __VdlyVal__top_accelerator__DOT__fifo_b__DOT__mem__v0;
    __VdlyVal__top_accelerator__DOT__fifo_b__DOT__mem__v0 = 0;
    CData/*3:0*/ __VdlyDim0__top_accelerator__DOT__fifo_b__DOT__mem__v0;
    __VdlyDim0__top_accelerator__DOT__fifo_b__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__top_accelerator__DOT__fifo_b__DOT__mem__v0;
    __VdlySet__top_accelerator__DOT__fifo_b__DOT__mem__v0 = 0;
    // Body
    __VdlySet__top_accelerator__DOT__fifo_a__DOT__mem__v0 = 0U;
    __VdlySet__top_accelerator__DOT__fifo_b__DOT__mem__v0 = 0U;
    if (vlSelfRef.rst_n) {
        vlSelfRef.top_accelerator__DOT__valid_pipe 
            = ((2U & ((IData)(vlSelfRef.top_accelerator__DOT__valid_pipe) 
                      << 1U)) | (1U & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_empty))));
        if (((IData)(vlSelfRef.wr_en) & (~ (IData)(vlSelfRef.fifo_full)))) {
            __VdlyVal__top_accelerator__DOT__fifo_a__DOT__mem__v0 
                = vlSelfRef.din_a;
            __VdlyDim0__top_accelerator__DOT__fifo_a__DOT__mem__v0 
                = (0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr));
            __VdlySet__top_accelerator__DOT__fifo_a__DOT__mem__v0 = 1U;
            vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr)));
        }
        if (((IData)(vlSelfRef.wr_en) & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__full)))) {
            __VdlyVal__top_accelerator__DOT__fifo_b__DOT__mem__v0 
                = vlSelfRef.din_b;
            __VdlyDim0__top_accelerator__DOT__fifo_b__DOT__mem__v0 
                = (0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr));
            __VdlySet__top_accelerator__DOT__fifo_b__DOT__mem__v0 = 1U;
            vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr)));
        }
        if (vlSelfRef.acc_clr) {
            vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg = 0U;
        } else if ((1U & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_empty)))) {
            vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg 
                = vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc;
        }
        if ((1U & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_empty)))) {
            vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg 
                = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelfRef.top_accelerator__DOT__fifo_a_out)), 
                              VL_EXTENDS_II(32,16, (IData)(vlSelfRef.top_accelerator__DOT__fifo_b_out)));
            vlSelfRef.top_accelerator__DOT__fifo_a_out 
                = vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem
                [(0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr))];
            vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr)));
        }
        if ((1U & ((~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_empty)) 
                   & (~ (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__empty))))) {
            vlSelfRef.top_accelerator__DOT__fifo_b_out 
                = vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem
                [(0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr))];
            vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr 
                = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr)));
        }
    } else {
        vlSelfRef.top_accelerator__DOT__valid_pipe = 0U;
        vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr = 0U;
        vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr = 0U;
        vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg = 0U;
        vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg = 0U;
        vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr = 0U;
        vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr = 0U;
    }
    vlSelfRef.valid_out = (1U & ((IData)(vlSelfRef.top_accelerator__DOT__valid_pipe) 
                                 >> 1U));
    vlSelfRef.acc_out = vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg;
    vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc 
        = (vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg 
           + vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg);
    if (((VL_LTS_III(32, 0U, vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg) 
          & VL_LTS_III(32, 0U, vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg)) 
         & VL_GTS_III(32, 0U, vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc))) {
        vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc = 0x7fffffffU;
    } else if (((VL_GTS_III(32, 0U, vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg) 
                 & VL_GTS_III(32, 0U, vlSelfRef.top_accelerator__DOT__processor__DOT__mult_reg)) 
                & VL_LTS_III(32, 0U, vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc))) {
        vlSelfRef.top_accelerator__DOT__processor__DOT__next_acc = 0x80000000U;
    }
    if (__VdlySet__top_accelerator__DOT__fifo_a__DOT__mem__v0) {
        vlSelfRef.top_accelerator__DOT__fifo_a__DOT__mem[__VdlyDim0__top_accelerator__DOT__fifo_a__DOT__mem__v0] 
            = __VdlyVal__top_accelerator__DOT__fifo_a__DOT__mem__v0;
    }
    if (__VdlySet__top_accelerator__DOT__fifo_b__DOT__mem__v0) {
        vlSelfRef.top_accelerator__DOT__fifo_b__DOT__mem[__VdlyDim0__top_accelerator__DOT__fifo_b__DOT__mem__v0] 
            = __VdlyVal__top_accelerator__DOT__fifo_b__DOT__mem__v0;
    }
    vlSelfRef.fifo_full = (((1U & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr) 
                                   >> 4U)) != (1U & 
                                               ((IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr) 
                                                >> 4U))) 
                           & ((0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr)) 
                              == (0x0000000fU & (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr))));
    vlSelfRef.top_accelerator__DOT__fifo_empty = ((IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__rd_ptr) 
                                                  == (IData)(vlSelfRef.top_accelerator__DOT__fifo_a__DOT__wr_ptr));
    vlSelfRef.top_accelerator__DOT__fifo_b__DOT__empty 
        = ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr) 
           == (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr));
    vlSelfRef.top_accelerator__DOT__fifo_b__DOT__full 
        = (((1U & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr) 
                   >> 4U)) != (1U & ((IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr) 
                                     >> 4U))) & ((0x0000000fU 
                                                  & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__wr_ptr)) 
                                                 == 
                                                 (0x0000000fU 
                                                  & (IData)(vlSelfRef.top_accelerator__DOT__fifo_b__DOT__rd_ptr))));
}

void Vtop_accelerator___024root___eval_nba(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_nba\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_accelerator___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop_accelerator___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop_accelerator___024root___eval_phase__act(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_phase__act\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_accelerator___024root___eval_triggers__act(vlSelf);
    Vtop_accelerator___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop_accelerator___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop_accelerator___024root___eval_phase__nba(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_phase__nba\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop_accelerator___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop_accelerator___024root___eval_nba(vlSelf);
        Vtop_accelerator___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop_accelerator___024root___eval(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop_accelerator___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("src/top_accelerator.sv", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop_accelerator___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("src/top_accelerator.sv", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vtop_accelerator___024root___eval_phase__act(vlSelf));
    } while (Vtop_accelerator___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vtop_accelerator___024root___eval_debug_assertions(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_debug_assertions\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.wr_en & 0xfeU)))) {
        Verilated::overWidthError("wr_en");
    }
    if (VL_UNLIKELY(((vlSelfRef.acc_clr & 0xfeU)))) {
        Verilated::overWidthError("acc_clr");
    }
}
#endif  // VL_DEBUG
