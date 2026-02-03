// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_accelerator.h for the primary calling header

#include "Vtop_accelerator__pch.h"

VL_ATTR_COLD void Vtop_accelerator___024root___eval_static(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_static\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vtop_accelerator___024root___eval_initial(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_initial\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop_accelerator___024root___eval_final(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_final\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_accelerator___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_accelerator___024root___eval_phase__stl(Vtop_accelerator___024root* vlSelf);

VL_ATTR_COLD void Vtop_accelerator___024root___eval_settle(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_settle\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop_accelerator___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("src/top_accelerator.sv", 3, "", "Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtop_accelerator___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtop_accelerator___024root___eval_triggers__stl(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_triggers__stl\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_accelerator___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtop_accelerator___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_accelerator___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_accelerator___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop_accelerator___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vtop_accelerator___024root___stl_sequent__TOP__0(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___stl_sequent__TOP__0\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.acc_out = vlSelfRef.top_accelerator__DOT__processor__DOT__acc_reg;
    vlSelfRef.valid_out = (1U & ((IData)(vlSelfRef.top_accelerator__DOT__valid_pipe) 
                                 >> 1U));
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

VL_ATTR_COLD void Vtop_accelerator___024root____Vm_traceActivitySetAll(Vtop_accelerator___024root* vlSelf);

VL_ATTR_COLD void Vtop_accelerator___024root___eval_stl(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_stl\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtop_accelerator___024root___stl_sequent__TOP__0(vlSelf);
        Vtop_accelerator___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD bool Vtop_accelerator___024root___eval_phase__stl(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___eval_phase__stl\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop_accelerator___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtop_accelerator___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop_accelerator___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtop_accelerator___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_accelerator___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop_accelerator___024root___trigger_anySet__act(triggers))))) {
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

VL_ATTR_COLD void Vtop_accelerator___024root____Vm_traceActivitySetAll(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root____Vm_traceActivitySetAll\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
}

VL_ATTR_COLD void Vtop_accelerator___024root___ctor_var_reset(Vtop_accelerator___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_accelerator___024root___ctor_var_reset\n"); );
    Vtop_accelerator__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710928637576349896ull);
    vlSelf->din_a = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 17772284259437899523ull);
    vlSelf->din_b = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6747305772072626686ull);
    vlSelf->fifo_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4782710040797492827ull);
    vlSelf->acc_clr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1614537328018866142ull);
    vlSelf->acc_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15809775069397034522ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->top_accelerator__DOT__fifo_a_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10440203722563088077ull);
    vlSelf->top_accelerator__DOT__fifo_b_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 8425622211419089525ull);
    vlSelf->top_accelerator__DOT__fifo_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1228227519125214404ull);
    vlSelf->top_accelerator__DOT__valid_pipe = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12992799514090391301ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top_accelerator__DOT__fifo_a__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4811659562503257035ull);
    }
    vlSelf->top_accelerator__DOT__fifo_a__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 10831932050087799930ull);
    vlSelf->top_accelerator__DOT__fifo_a__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 6294393212632573216ull);
    vlSelf->top_accelerator__DOT__fifo_b__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16947099912910873604ull);
    vlSelf->top_accelerator__DOT__fifo_b__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11863357456614379909ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->top_accelerator__DOT__fifo_b__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16829772751194456298ull);
    }
    vlSelf->top_accelerator__DOT__fifo_b__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 14111600685827826924ull);
    vlSelf->top_accelerator__DOT__fifo_b__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 2195650716634687632ull);
    vlSelf->top_accelerator__DOT__processor__DOT__mult_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 350887360678751232ull);
    vlSelf->top_accelerator__DOT__processor__DOT__acc_reg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11049131275610955335ull);
    vlSelf->top_accelerator__DOT__processor__DOT__next_acc = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18182793768765788446ull);
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
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
