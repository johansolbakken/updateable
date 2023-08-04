#include "application.h"

#include <iostream>

namespace Updateable
{
    static Application *s_instance = nullptr;

    Application &Application::instance()
    {
        return *s_instance;
    }

    Application::Application(const ApplicationSpecification &spec)
        : m_spec(spec)
    {
        s_instance = this;
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