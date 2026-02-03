// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPWM_CONTROLLER__SYMS_H_
#define VERILATED_VPWM_CONTROLLER__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vpwm_controller.h"

// INCLUDE MODULE CLASSES
#include "Vpwm_controller___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vpwm_controller__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vpwm_controller* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vpwm_controller___024root      TOP;

    // CONSTRUCTORS
    Vpwm_controller__Syms(VerilatedContext* contextp, const char* namep, Vpwm_controller* modelp);
    ~Vpwm_controller__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
