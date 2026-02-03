// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac_unit.h for the primary calling header

#include "Vmac_unit__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac_unit___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vmac_unit___024root___eval_triggers__act(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_triggers__act\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
        Vmac_unit___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vmac_unit___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___trigger_anySet__act\n"); );
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

void Vmac_unit___024root___nba_sequent__TOP__0(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___nba_sequent__TOP__0\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__mac_unit__DOT__acc_reg;
    __Vdly__mac_unit__DOT__acc_reg = 0;
    // Body
    __Vdly__mac_unit__DOT__acc_reg = vlSelfRef.mac_unit__DOT__acc_reg;
    if (vlSelfRef.rst_n) {
        if (vlSelfRef.clr) {
            __Vdly__mac_unit__DOT__acc_reg = 0U;
        } else if (vlSelfRef.en) {
            __Vdly__mac_unit__DOT__acc_reg = (vlSelfRef.mac_unit__DOT__acc_reg 
                                              + vlSelfRef.mac_unit__DOT__mult_reg);
        }
        if (vlSelfRef.en) {
            vlSelfRef.mac_unit__DOT__mult_reg = VL_MULS_III(32, 
                                                            VL_EXTENDS_II(32,16, (IData)(vlSelfRef.a_in)), 
                                                            VL_EXTENDS_II(32,16, (IData)(vlSelfRef.b_in)));
        }
    } else {
        __Vdly__mac_unit__DOT__acc_reg = 0U;
        vlSelfRef.mac_unit__DOT__mult_reg = 0U;
    }
    vlSelfRef.mac_unit__DOT__acc_reg = __Vdly__mac_unit__DOT__acc_reg;
    vlSelfRef.out = vlSelfRef.mac_unit__DOT__acc_reg;
}

void Vmac_unit___024root___eval_nba(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_nba\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vmac_unit___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vmac_unit___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vmac_unit___024root___eval_phase__act(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_phase__act\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vmac_unit___024root___eval_triggers__act(vlSelf);
    Vmac_unit___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vmac_unit___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vmac_unit___024root___eval_phase__nba(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_phase__nba\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vmac_unit___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vmac_unit___024root___eval_nba(vlSelf);
        Vmac_unit___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vmac_unit___024root___eval(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vmac_unit___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("src/mac_unit.sv", 3, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vmac_unit___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("src/mac_unit.sv", 3, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vmac_unit___024root___eval_phase__act(vlSelf));
    } while (Vmac_unit___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vmac_unit___024root___eval_debug_assertions(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_debug_assertions\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.en & 0xfeU)))) {
        Verilated::overWidthError("en");
    }
    if (VL_UNLIKELY(((vlSelfRef.clr & 0xfeU)))) {
        Verilated::overWidthError("clr");
    }
}
#endif  // VL_DEBUG
