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

    class Application
    {
    public:
        Application(const ApplicationSpecification &spec);
        virtual ~Application();

        void run();

        void pushLayer(Layer *layer);

    private:
        ApplicationSpecification m_spec;
        std::vector<Layer *> m_layers;
    };
}