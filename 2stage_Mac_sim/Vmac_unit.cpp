// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmac_unit__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmac_unit::Vmac_unit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmac_unit__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , en{vlSymsp->TOP.en}
    , clr{vlSymsp->TOP.clr}
    , a_in{vlSymsp->TOP.a_in}
    , b_in{vlSymsp->TOP.b_in}
    , out{vlSymsp->TOP.out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmac_unit::Vmac_unit(const char* _vcname__)
    : Vmac_unit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmac_unit::~Vmac_unit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmac_unit___024root___eval_debug_assertions(Vmac_unit___024root* vlSelf);
#endif  // VL_DEBUG
void Vmac_unit___024root___eval_static(Vmac_unit___024root* vlSelf);
void Vmac_unit___024root___eval_initial(Vmac_unit___024root* vlSelf);
void Vmac_unit___024root___eval_settle(Vmac_unit___024root* vlSelf);
void Vmac_unit___024root___eval(Vmac_unit___024root* vlSelf);

void Vmac_unit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmac_unit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmac_unit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmac_unit___024root___eval_static(&(vlSymsp->TOP));
        Vmac_unit___024root___eval_initial(&(vlSymsp->TOP));
        Vmac_unit___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmac_unit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmac_unit::eventsPending() { return false; }

uint64_t Vmac_unit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmac_unit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmac_unit___024root___eval_final(Vmac_unit___024root* vlSelf);

VL_ATTR_COLD void Vmac_unit::final() {
    Vmac_unit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmac_unit::hierName() const { return vlSymsp->name(); }
const char* Vmac_unit::modelName() const { return "Vmac_unit"; }
unsigned Vmac_unit::threads() const { return 1; }
void Vmac_unit::prepareClone() const { contextp()->prepareClone(); }
void Vmac_unit::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmac_unit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vmac_unit___024root__trace_decl_types(VerilatedVcd* tracep);

void Vmac_unit___024root__trace_init_top(Vmac_unit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmac_unit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac_unit___024root*>(voidSelf);
    Vmac_unit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vmac_unit___024root__trace_decl_types(tracep);
    Vmac_unit___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmac_unit___024root__trace_register(Vmac_unit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmac_unit::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmac_unit::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vmac_unit___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
