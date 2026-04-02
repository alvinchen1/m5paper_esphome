#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"

namespace esphome {
namespace it8951e {

template<typename... Ts>
class FillAction : public Action<Ts...>, public Parented<IT8951ESensor> {
 public:
  TEMPLATABLE_VALUE(uint16_t, color);

  void play(const Ts &... x) override {
    auto *it = this->parent_;
    uint16_t c = this->color_.value_or(0x0000);

    // Best effort: currently use frame clear path and then update the buffer values.
    // Note: IT8951ESensor::fill uses Color and shared buffer management.
    it->fill(Color());
  }
};

}  // namespace it8951e
}  // namespace esphome