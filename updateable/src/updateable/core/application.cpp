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
        std::cout << "Running application " << m_spec.name << "\n";
        while (true)
            ;
    }
}