//
// Created by crist on 20/01/2021.
//

#ifndef MYHAZEL_LAYER_HPP
#define MYHAZEL_LAYER_HPP

#include "Events/Event.hpp"

namespace Hazel
{
    class HAZEL_API Layer
    {
    public:
        explicit Layer(std::string  name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& event) {}

        [[nodiscard]] inline const std::string& GetName() const { return m_DebugName; }

    private:
        std::string m_DebugName;
    };
}

#endif //MYHAZEL_LAYER_HPP
