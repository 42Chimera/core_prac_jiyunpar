#pragma once

#include "event.h"

namespace Chimera {
class CHIMERA_API KeyEvent : public Event {
   public:
    int GetKeyCode() const { return mKeyCode; }

    EVENT_CLASS_CATEGORY(EventCategoryKeyBoard | EventCategoryInput)
   protected:
    KeyEvent(int keycode) : mKeyCode(keycode) {}

    int mKeyCode;
};
}  // namespace Chimera