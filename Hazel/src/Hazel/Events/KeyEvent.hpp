//
// Created by crist on 17/01/2021.
//

#ifndef MYHAZEL_KEYEVENT_HPP
#define MYHAZEL_KEYEVENT_HPP

#include "Event.hpp"

namespace Hazel
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-token-paste"
    class HAZEL_API KeyEvent : public Event
    {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        explicit KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

        int m_KeyCode;
    };

    class HAZEL_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int m_RepeatCount;
    };

    class HAZEL_API KeyReleasedEvent : public KeyEvent
    {
    public:
        explicit KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
#pragma clang diagnostic pop
}

#endif //MYHAZEL_KEYEVENT_HPP
