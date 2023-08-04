#include "application.h"

#include <iostream>

namespace Updateable
{
    Application::Application(const ApplicationSpecification &spec)
        : m_spec(spec)
    {
    }

    Application::~Application()
    {
    }

    void Application::run()
    {
        for (auto layer : m_layers)
            layer->onAttach();

        while (true)
        {
            for (auto layer : m_layers)
                layer->onUpdate();
        }

        for (auto layer : m_layers)
            layer->onDetach();
    }

    void Application::pushLayer(Layer *layer)
    {
        m_layers.push_back(layer);
    }
}