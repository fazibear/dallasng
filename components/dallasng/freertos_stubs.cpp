#include "Arduino.h"

// FreeRTOS compatibility stubs for LibreTiny platform
// These functions provide basic interrupt masking functionality

extern "C" {

// Stub for ulPortSetInterruptMask - disable interrupts and return previous state
unsigned long ulPortSetInterruptMask(void)
{
    // For LibreTiny/BK72xx, we can use the standard Arduino interrupt control
    unsigned long prev_state = 0;
    noInterrupts();
    return prev_state;
}

// Stub for vPortClearInterruptMask - restore previous interrupt state
void vPortClearInterruptMask(unsigned long uxSavedInterruptStatus)
{
    // For LibreTiny/BK72xx, we can use the standard Arduino interrupt control
    (void)uxSavedInterruptStatus; // Unused parameter
    interrupts();
}

}