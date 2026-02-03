// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac_unit.h for the primary calling header

#include "Vmac_unit__pch.h"

VL_ATTR_COLD void Vmac_unit___024root___eval_static(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_static\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vmac_unit___024root___eval_initial(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_initial\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmac_unit___024root___eval_final(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_final\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac_unit___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vmac_unit___024root___eval_phase__stl(Vmac_unit___024root* vlSelf);

VL_ATTR_COLD void Vmac_unit___024root___eval_settle(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_settle\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vmac_unit___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("src/mac_unit.sv", 3, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vmac_unit___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vmac_unit___024root___eval_triggers__stl(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_triggers__stl\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmac_unit___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vmac_unit___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac_unit___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vmac_unit___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vmac_unit___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vmac_unit___024root___stl_sequent__TOP__0(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___stl_sequent__TOP__0\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.out = vlSelfRef.mac_unit__DOT__acc_reg;
}

VL_ATTR_COLD void Vmac_unit___024root___eval_stl(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_stl\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vmac_unit___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vmac_unit___024root___eval_phase__stl(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___eval_phase__stl\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vmac_unit___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vmac_unit___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vmac_unit___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vmac_unit___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac_unit___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vmac_unit___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmac_unit___024root___ctor_var_reset(Vmac_unit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac_unit___024root___ctor_var_reset\n"); );
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710216835639188562ull);
    vlSelf->clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2963062549562832118ull);
    vlSelf->a_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13389479046651284173ull);
    vlSelf->b_in = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13248153975629471093ull);
    vlSelf->out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7519490245117619040ull);
    vlSelf->mac_unit__DOT__mult_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1984205019204449218ull);
    vlSelf->mac_unit__DOT__acc_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16614232285872974932ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
