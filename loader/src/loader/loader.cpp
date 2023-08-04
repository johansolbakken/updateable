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
        std::cout << "Will load from " << m_spec.srcPath << "\n;";
    }

    Loader::~Loader()
    {
    }

    void Loader::run()
    {
        std::string srcPath = m_spec.srcPath;
        std::string buildPath = srcPath + "/" + m_spec.name + "/build";
        std::string dylibName = "lib" + m_spec.name + ".dylib";

        std::string cmakeCommand = "cmake -S " + srcPath + " -B " + buildPath;
        std::string buildCommand = "cmake --build " + buildPath;
        std::cout << "Running " << cmakeCommand << "\n";
        system(cmakeCommand.c_str());
        std::cout << "Running " << buildCommand << "\n";
        system(buildCommand.c_str());

        // recursive search for dylib
        std::string dylibPath;
        std::function<void(std::string)> search;
        search = [&search, &dylibPath, &dylibName](std::string path) {
            for (const auto &entry : std::filesystem::directory_iterator(path))
            {
                if (entry.is_directory())
                {
                    search(entry.path().string());
                }
                else if (entry.is_regular_file())
                {
                    if (entry.path().filename().string() == dylibName)
                    {
                        dylibPath = entry.path().string();
                        return;
                    }
                }
            }
        };
        search(buildPath);

        if (dylibPath.empty())
        {
            std::cout << "Could not find dylib\n";
            return;
        }

        std::cout << "Loading dylib from " << dylibPath << "\n";

        void *handle = dlopen(dylibPath.c_str(), RTLD_LAZY);
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