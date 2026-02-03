// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vblinky.h for the primary calling header

#include "Vblinky__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vblinky___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vblinky___024root___eval_triggers__act(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_triggers__act\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((IData)(vlSelfRef.rst) 
                                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vblinky___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vblinky___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___trigger_anySet__act\n"); );
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

void Vblinky___024root___nba_sequent__TOP__0(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___nba_sequent__TOP__0\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__blinky__DOT__count;
    __Vdly__blinky__DOT__count = 0;
    CData/*0:0*/ __Vdly__led;
    __Vdly__led = 0;
    // Body
    __Vdly__blinky__DOT__count = vlSelfRef.blinky__DOT__count;
    __Vdly__led = vlSelfRef.led;
    if (vlSelfRef.rst) {
        __Vdly__blinky__DOT__count = 0U;
        __Vdly__led = 0U;
    } else {
        __Vdly__blinky__DOT__count = (0x0000000fU & 
                                      ((IData)(1U) 
                                       + (IData)(vlSelfRef.blinky__DOT__count)));
        if ((0x0fU == (IData)(vlSelfRef.blinky__DOT__count))) {
            __Vdly__led = (1U & (~ (IData)(vlSelfRef.led)));
        }
    }
    vlSelfRef.blinky__DOT__count = __Vdly__blinky__DOT__count;
    vlSelfRef.led = __Vdly__led;
}

void Vblinky___024root___eval_nba(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_nba\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vblinky___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vblinky___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vblinky___024root___eval_phase__act(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_phase__act\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vblinky___024root___eval_triggers__act(vlSelf);
    Vblinky___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vblinky___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vblinky___024root___eval_phase__nba(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_phase__nba\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vblinky___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vblinky___024root___eval_nba(vlSelf);
        Vblinky___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vblinky___024root___eval(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vblinky___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("src/blinky.sv", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vblinky___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("src/blinky.sv", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vblinky___024root___eval_phase__act(vlSelf));
    } while (Vblinky___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vblinky___024root___eval_debug_assertions(Vblinky___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vblinky___024root___eval_debug_assertions\n"); );
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
