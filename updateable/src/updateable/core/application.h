#pragma once

#include <string>

namespace Updateable
{
    struct ApplicationSpecification
    {
        std::string name;
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification &spec);
        virtual ~Application();

        void run();

    private:
        ApplicationSpecification m_spec;
    };
}