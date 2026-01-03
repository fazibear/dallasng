#pragma once

// Define configuration macros before including any OneWireNg headers
#ifndef CONFIG_BITBANG_TIMING
#define CONFIG_BITBANG_TIMING 2  // TIMING_NULL
#endif

#ifndef CONFIG_BUS_BLINK_PROTECTION
#define CONFIG_BUS_BLINK_PROTECTION 1
#endif

#ifndef CONFIG_OVERDRIVE_ENABLED
#define CONFIG_OVERDRIVE_ENABLED 0
#endif

#include "OneWireNg_BitBang.h"

/**
 * LibreTiny platform GPIO specific implementation using bit-banging.
 * This implementation works with LibreTiny platforms like BK72xx chips.
 */
class OneWireNg_LibreTiny: public OneWireNg_BitBang
{
public:
    /**
     * OneWireNg 1-wire service for LibreTiny platform.
     *
     * @param pin GPIO pin number used for bit-banging 1-wire bus.
     * @param pullUp If @c true configure internal pull-up resistor for the bus.
     */
    OneWireNg_LibreTiny(unsigned pin, bool pullUp) : _pin(pin), _pullUp(pullUp)
    {
        setupDtaGpio();
    }

protected:
    int readDtaGpioIn() override
    {
        return digitalRead(_pin);
    }

    void setDtaGpioAsInput() override
    {
        if (_pullUp) {
            pinMode(_pin, INPUT_PULLUP);
        } else {
            pinMode(_pin, INPUT);
        }
    }

    void writeGpioOut(int state) override
    {
        digitalWrite(_pin, state);
    }

    void setGpioAsOutput(int state) override
    {
        pinMode(_pin, OUTPUT);
        digitalWrite(_pin, state);
    }

private:
    unsigned _pin;
    bool _pullUp;
};