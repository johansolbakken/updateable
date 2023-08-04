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

    ExitStatus Application::run()
    {
        for (auto layer : m_layers)
            layer->onAttach();

        while (m_running)
        {
            for (auto layer : m_layers)
                layer->onUpdate();
        }

        for (auto layer : m_layers)
            layer->onDetach();

        return m_exitStatus;
    }

    void Application::close()
    {
        m_running = false;
        m_exitStatus = ExitStatus::Exit;
    }

    void Application::restart()
    {
        m_running = false;
        m_exitStatus = ExitStatus::Restart;
    }

    void Application::pushLayer(Layer *layer)
    {
        m_layers.push_back(layer);
    }
}