//
// Created by crist on 20/01/2021.
//

#include "Layer.hpp"

namespace Hazel
{
    Layer::Layer(std::string name) : m_DebugName(std::move(name))
    {

    }

    Layer::~Layer() = default;
}