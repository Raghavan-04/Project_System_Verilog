// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vblinky__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vblinky::Vblinky(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vblinky__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vblinky::Vblinky(const char* _vcname__)
    : Vblinky(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vblinky::~Vblinky() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vblinky___024root___eval_debug_assertions(Vblinky___024root* vlSelf);
#endif  // VL_DEBUG
void Vblinky___024root___eval_static(Vblinky___024root* vlSelf);
void Vblinky___024root___eval_initial(Vblinky___024root* vlSelf);
void Vblinky___024root___eval_settle(Vblinky___024root* vlSelf);
void Vblinky___024root___eval(Vblinky___024root* vlSelf);

void Vblinky::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vblinky::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vblinky___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vblinky___024root___eval_static(&(vlSymsp->TOP));
        Vblinky___024root___eval_initial(&(vlSymsp->TOP));
        Vblinky___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vblinky___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vblinky::eventsPending() { return false; }

uint64_t Vblinky::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vblinky::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vblinky___024root___eval_final(Vblinky___024root* vlSelf);

VL_ATTR_COLD void Vblinky::final() {
    Vblinky___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vblinky::hierName() const { return vlSymsp->name(); }
const char* Vblinky::modelName() const { return "Vblinky"; }
unsigned Vblinky::threads() const { return 1; }
void Vblinky::prepareClone() const { contextp()->prepareClone(); }
void Vblinky::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vblinky::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vblinky___024root__trace_decl_types(VerilatedVcd* tracep);

void Vblinky___024root__trace_init_top(Vblinky___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vblinky___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vblinky___024root*>(voidSelf);
    Vblinky__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vblinky___024root__trace_decl_types(tracep);
    Vblinky___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vblinky___024root__trace_register(Vblinky___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vblinky::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vblinky::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vblinky___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
