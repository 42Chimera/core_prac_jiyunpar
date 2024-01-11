#pragma once

#include "pch.h"
#include "event.h"

namespace Chimera {
class CHIMERA_API Layer {
public:
  Layer(const std::string& name = "Layer");
  virtual ~Layer() = default;

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate() {}
  virtual void OnEvent(Event& event) {}

  const std::string& GetName() const { return mDebugname; }

protected:
  std::string mDebugname;
};
} // namespace Chimera