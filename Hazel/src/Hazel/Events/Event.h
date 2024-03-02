#pragma once

#include "Hazel/Core.h"
#include "hzpch.h"

#include <spdlog/fmt/ostr.h>

namespace Hazel
{
    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard= BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4),
    };

#define EVENT_CLASS_TYPE(type) [[nodiscard]] static EventType GetStaticType() { return EventType::##type; } \
                               [[nodiscard]] virtual EventType GetEventType() const override { return GetStaticType(); } \
                               [[nodiscard]] virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) [[nodiscard]] virtual int GetCategoryFlags() const override { return category; }

    class HAZEL_API Event
    {
        friend class EventDispatcher;

    public:
        [[nodiscard]] virtual EventType GetEventType() const = 0;
        [[nodiscard]] virtual const char* GetName() const = 0;
        [[nodiscard]] virtual int GetCategoryFlags() const = 0;
        [[nodiscard]] virtual std::string ToString() const { return GetName(); }

        [[nodiscard]] bool IsInCategory(const EventCategory category) const
        {
            return GetCategoryFlags() & category;
        }
        
        bool Handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        explicit EventDispatcher(Event& event)
            : m_Event(event)
        {
        }

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.Handled = func(*static_cast<T*>(&m_Event));
                return true;
            }

            return false;
        }

    private:
        Event& m_Event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}
