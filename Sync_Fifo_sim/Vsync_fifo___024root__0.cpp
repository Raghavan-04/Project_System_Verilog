// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsync_fifo.h for the primary calling header

#include "Vsync_fifo__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsync_fifo___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vsync_fifo___024root___eval_triggers__act(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_triggers__act\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
        Vsync_fifo___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vsync_fifo___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___trigger_anySet__act\n"); );
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

void Vsync_fifo___024root___nba_sequent__TOP__0(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___nba_sequent__TOP__0\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __VdlyVal__sync_fifo__DOT__mem__v0;
    __VdlyVal__sync_fifo__DOT__mem__v0 = 0;
    CData/*2:0*/ __VdlyDim0__sync_fifo__DOT__mem__v0;
    __VdlyDim0__sync_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__sync_fifo__DOT__mem__v0;
    __VdlySet__sync_fifo__DOT__mem__v0 = 0;
    // Body
    __VdlySet__sync_fifo__DOT__mem__v0 = 0U;
    if (vlSelfRef.rst_n) {
        if (((IData)(vlSelfRef.wr_en) & (~ (IData)(vlSelfRef.full)))) {
            __VdlyVal__sync_fifo__DOT__mem__v0 = vlSelfRef.din;
            __VdlyDim0__sync_fifo__DOT__mem__v0 = (7U 
                                                   & (IData)(vlSelfRef.sync_fifo__DOT__wr_ptr));
            __VdlySet__sync_fifo__DOT__mem__v0 = 1U;
            vlSelfRef.sync_fifo__DOT__wr_ptr = (0x0000000fU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.sync_fifo__DOT__wr_ptr)));
        }
        if (((IData)(vlSelfRef.rd_en) & (~ (IData)(vlSelfRef.empty)))) {
            vlSelfRef.dout = vlSelfRef.sync_fifo__DOT__mem
                [(7U & (IData)(vlSelfRef.sync_fifo__DOT__rd_ptr))];
            vlSelfRef.sync_fifo__DOT__rd_ptr = (0x0000000fU 
                                                & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.sync_fifo__DOT__rd_ptr)));
        }
    } else {
        vlSelfRef.sync_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.sync_fifo__DOT__rd_ptr = 0U;
    }
    if (__VdlySet__sync_fifo__DOT__mem__v0) {
        vlSelfRef.sync_fifo__DOT__mem[__VdlyDim0__sync_fifo__DOT__mem__v0] 
            = __VdlyVal__sync_fifo__DOT__mem__v0;
    }
    vlSelfRef.full = (((1U & ((IData)(vlSelfRef.sync_fifo__DOT__wr_ptr) 
                              >> 3U)) != (1U & ((IData)(vlSelfRef.sync_fifo__DOT__rd_ptr) 
                                                >> 3U))) 
                      & ((7U & (IData)(vlSelfRef.sync_fifo__DOT__wr_ptr)) 
                         == (7U & (IData)(vlSelfRef.sync_fifo__DOT__rd_ptr))));
    vlSelfRef.empty = ((IData)(vlSelfRef.sync_fifo__DOT__rd_ptr) 
                       == (IData)(vlSelfRef.sync_fifo__DOT__wr_ptr));
}

void Vsync_fifo___024root___eval_nba(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_nba\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsync_fifo___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

void Vsync_fifo___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsync_fifo___024root___eval_phase__act(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_phase__act\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsync_fifo___024root___eval_triggers__act(vlSelf);
    Vsync_fifo___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vsync_fifo___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vsync_fifo___024root___eval_phase__nba(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_phase__nba\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsync_fifo___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vsync_fifo___024root___eval_nba(vlSelf);
        Vsync_fifo___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vsync_fifo___024root___eval(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vsync_fifo___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("src/sync_fifo.sv", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vsync_fifo___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("src/sync_fifo.sv", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vsync_fifo___024root___eval_phase__act(vlSelf));
    } while (Vsync_fifo___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vsync_fifo___024root___eval_debug_assertions(Vsync_fifo___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsync_fifo___024root___eval_debug_assertions\n"); );
    Vsync_fifo__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
    if (VL_UNLIKELY(((vlSelfRef.rd_en & 0xfeU)))) {
        Verilated::overWidthError("rd_en");
    }
}
#endif  // VL_DEBUG
