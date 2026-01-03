#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/core/hal.h"

#include "OneWireNg.h"
#include "OneWireNg_BitBang.h"
#include "OneWireNg_LibreTiny.h"
#include "drivers/DSTherm.h"

namespace esphome
{
  namespace dallasng
  {

    class DallasNgTemperatureSensor;

    class DallasNgComponent : public PollingComponent
    {
    public:
      void set_pin(InternalGPIOPin *pin);

      void setup() override;
      void dump_config() override;
      float get_setup_priority() const override { return setup_priority::DATA; }
      void register_sensor(DallasNgTemperatureSensor *sensor)
      {
        sensors_.push_back(sensor);
      }

      void update() override;

    protected:
      friend DallasNgTemperatureSensor;
      InternalGPIOPin *pin_;
      OneWireNg_LibreTiny *one_wire_;
      std::vector<uint64_t> found_sensors_;
      std::vector<DallasNgTemperatureSensor *> sensors_;
    };

  } // namespace dallasng
} // namespace esphome
