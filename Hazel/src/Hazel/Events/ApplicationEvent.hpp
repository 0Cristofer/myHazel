//
// Created by crist on 17/01/2021.
//

#ifndef MYHAZEL_APPLICATIONEVENT_HPP
#define MYHAZEL_APPLICATIONEVENT_HPP

#include "Event.hpp"

namespace Hazel
{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-token-paste"
    class HAZEL_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

        [[nodiscard]] inline unsigned int GetWidth() const { return m_Width; }
        [[nodiscard]] inline unsigned int GetHeight() const { return m_Height; }

        [[nodiscard]] std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_CATEGORY(EventCategoryApplication);
        EVENT_CLASS_TYPE(WindowResize)

    private:
        unsigned int m_Width, m_Height;
    };

    class HAZEL_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategoryApplication);
        EVENT_CLASS_TYPE(WindowClose)
    };

    class HAZEL_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategoryApplication);
        EVENT_CLASS_TYPE(AppTick)
    };

    class HAZEL_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategoryApplication);
        EVENT_CLASS_TYPE(AppUpdate)
    };

    class HAZEL_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() = default;

        EVENT_CLASS_CATEGORY(EventCategoryApplication);
        EVENT_CLASS_TYPE(AppRender)
    };
#pragma clang diagnostic pop
}

#endif //MYHAZEL_APPLICATIONEVENT_HPP
