#pragma once

#include "core.h"
#include "pch.h"

namespace Chimera {

enum class EventType {
    None = 0,
    WindowClose,
    WindowResize,
    KeyPress,
    KeyRelease,
    MouseMove,
    MouseButtonPress,
    MouseButtonRelease
};

enum EventCategory {
    None = 0,
    EventCategoryApplication = (1 << 0),
    EventCategoryInput = (1 << 1),
    EventCategoryKeyBoard = (1 << 2),
    EventCategoryMouse = (1 << 3),
    EventCategoryMouseButton = (1 << 4)
};

#define EVENT_CLASS_CATEGORY(category) \
    virtual GetCategoryFlags() const overide { return category; }

#define EVENT_CLASS_TYPE(type)                                                 \
    static EventType GetStaticType() { return EventType::##type; }             \
    virtual EventType GetEventType() const overide { return GetStaticType(); } \
    virtual const char* GetName() const overide { return #type; }

class CHIMERA_API Event {
   public:
    virtual EventType GetEventType() const = 0;
    virtual const char* GetName() const = 0;
    virtual int GetCategoryFlags() const = 0;
    virtual std::string ToString() const { return GetName(); }

    inline bool IsInCategory(EventCategory category) {
        return GetCategoryFlag() & category;
    }

    bool GetHandled() const { return mHandled; }
    void SetHandled(bool state) { mHandled = state; }

   private:
    bool mHandled = false;
};

class CHIMERA_API EventDispatcher {
    template <typename T>
    using EventFunction = std::function<bool(T&)>;

   public:
    EventDispatcher(Event& event) : mEvent(event) {}

    template <typename T>
    bool Dispatch(EventFunction<T> func) {
        if (mEvent.GetEventType() == T::GetStaticType()) {
            mEvent.SetHandled(func(static_cast<T>(mEvent)));
            return true;
        }
        return false;
    }

   private:
    Event& mEvent;
};

inline std::ostream& operator<<(std::ostream& os, const Event& event) {
    return os << event.ToString();
}
}  // namespace Chimera