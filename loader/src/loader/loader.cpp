#include "loader.h"

#include <iostream>

#include <updateable/updateable.h>

#include <dlfcn.h>

#include <functional>
#include <filesystem>

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
        void *handle = dlopen(name.c_str(), RTLD_LAZY);
        if (!handle)
        {
            std::cout << "Could not load dylib\n";
            return;
        }

        typedef Updateable::Application *(*CreateApplicationFn)();
        CreateApplicationFn createApplication = (CreateApplicationFn)dlsym(handle, "createApplication");

        if (!createApplication)
        {
            std::cout << "Could not find createApplication\n";
            return;
        }

        auto app = createApplication();
        app->run();
        delete app;

        while (true)
            ;
    }
}