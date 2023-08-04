#pragma once

#include <string>
#include <vector>

#include "updateable/core/layer.h"

namespace Updateable
{
    struct ApplicationSpecification
    {
        std::string name;
    };

    enum class ExitStatus
    {
        Exit,
        Restart
    };

    class Application
    {
    public:
        Application(const ApplicationSpecification &spec);
        virtual ~Application();

        ExitStatus run();

        void pushLayer(Layer *layer);

        void close();
        void restart();

    private:
        ApplicationSpecification m_spec;
        std::vector<Layer *> m_layers;

        ExitStatus m_exitStatus = ExitStatus::Exit;
        bool m_running = true;
    };
}