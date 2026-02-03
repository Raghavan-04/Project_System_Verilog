// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vpwm_controller__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vpwm_controller::Vpwm_controller(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vpwm_controller__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , duty_cycle{vlSymsp->TOP.duty_cycle}
    , pwm_out{vlSymsp->TOP.pwm_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vpwm_controller::Vpwm_controller(const char* _vcname__)
    : Vpwm_controller(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vpwm_controller::~Vpwm_controller() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vpwm_controller___024root___eval_debug_assertions(Vpwm_controller___024root* vlSelf);
#endif  // VL_DEBUG
void Vpwm_controller___024root___eval_static(Vpwm_controller___024root* vlSelf);
void Vpwm_controller___024root___eval_initial(Vpwm_controller___024root* vlSelf);
void Vpwm_controller___024root___eval_settle(Vpwm_controller___024root* vlSelf);
void Vpwm_controller___024root___eval(Vpwm_controller___024root* vlSelf);

void Vpwm_controller::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vpwm_controller::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vpwm_controller___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vpwm_controller___024root___eval_static(&(vlSymsp->TOP));
        Vpwm_controller___024root___eval_initial(&(vlSymsp->TOP));
        Vpwm_controller___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vpwm_controller___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vpwm_controller::eventsPending() { return false; }

uint64_t Vpwm_controller::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vpwm_controller::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vpwm_controller___024root___eval_final(Vpwm_controller___024root* vlSelf);

VL_ATTR_COLD void Vpwm_controller::final() {
    Vpwm_controller___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vpwm_controller::hierName() const { return vlSymsp->name(); }
const char* Vpwm_controller::modelName() const { return "Vpwm_controller"; }
unsigned Vpwm_controller::threads() const { return 1; }
void Vpwm_controller::prepareClone() const { contextp()->prepareClone(); }
void Vpwm_controller::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vpwm_controller::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vpwm_controller___024root__trace_decl_types(VerilatedVcd* tracep);

void Vpwm_controller___024root__trace_init_top(Vpwm_controller___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vpwm_controller___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vpwm_controller___024root*>(voidSelf);
    Vpwm_controller__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vpwm_controller___024root__trace_decl_types(tracep);
    Vpwm_controller___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vpwm_controller___024root__trace_register(Vpwm_controller___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vpwm_controller::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vpwm_controller::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vpwm_controller___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
