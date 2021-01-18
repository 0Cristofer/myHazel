//
// Created by crist on 17/01/2021.
//

#ifndef MYHAZEL_MOUSEEVENT_HPP
#define MYHAZEL_MOUSEEVENT_HPP

#include "Event.hpp"

#include <sstream>

namespace Hazel
{
    class HAZEL_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}

        inline float getMouseX() const { return m_MouseX; }
        inline float getMouseY() const { return m_MouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseY << ", " << m_MouseY;

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    private:
        float m_MouseX, m_MouseY;
    };

    class HAZEL_API MouseScroledEvent : public Event
    {
    public:
        MouseScroledEvent(float mXOffset, float mYOffset) : m_XOffset(mXOffset), m_YOffset(mYOffset) {}

        inline float getMXOffset() const { return m_XOffset; }
        inline float getMYOffset() const { return m_YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
    private:
        float m_XOffset, m_YOffset;
    };

    class HAZEL_API MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton () const { return m_Button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)

    protected:
        MouseButtonEvent(int button) : m_Button(button) {}

        int m_Button;
    };

    class HAZEL_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class HAZEL_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseReleasedPressedEvent: " << m_Button;

            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}

#endif //MYHAZEL_MOUSEEVENT_HPP