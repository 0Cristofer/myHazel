//
// Created by crist on 20/01/2021.
//

#include "LayerStack.hpp"

namespace Hazel
{
    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer *layer)
    {
        m_Layers.emplace(begin() + m_LayerInsertIndex, layer);
        m_LayerInsertIndex++;
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        auto lastIt = begin() + m_LayerInsertIndex;
        auto it = std::find(begin(), lastIt, layer);

        if (it != lastIt)
        {
            layer->OnDetach();
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(Layer *overlay)
    {
        auto firstIt = begin() + m_LayerInsertIndex;
        auto it = std::find(firstIt, end(), overlay);

        if (it != end())
        {
            overlay->OnDetach();
            m_Layers.erase(it);
        }
    }
}