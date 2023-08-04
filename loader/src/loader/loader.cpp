#include "loader.h"

#include <updateable/updateable.h>

#include "loader/dylib.h"

namespace Updateable
{
    Loader::Loader(const LoaderSpecification &spec)
        : m_spec(spec)
    {
    }

    Loader::~Loader()
    {
    }

    void Loader::run()
    {
        std::string name = "lib" + m_spec.name + ".dylib";

        ExitStatus exitStatus = ExitStatus::Exit;
        do
        {
            Dylib dylib(name);
            auto app = dylib.getSymbol<Updateable::Application *(*)()>("createApplication")();
            if (!app)
            {
                std::cout << "Could not load application\n";
                return;
            }
            exitStatus = app->run();
            delete app;
        } while (exitStatus == ExitStatus::Restart);
    }
}