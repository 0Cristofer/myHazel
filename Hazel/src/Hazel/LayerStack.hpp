//
// Created by crist on 20/01/2021.
//

#ifndef MYHAZEL_LAYERSTACK_HPP
#define MYHAZEL_LAYERSTACK_HPP

#include "Layer.hpp"

namespace Hazel
{
    class HAZEL_API LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer*> m_Layers;
        unsigned int m_LayerInsertIndex = 0;
    };
}

#endif //MYHAZEL_LAYERSTACK_HPP
