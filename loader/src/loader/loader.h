#pragma once

#include <string>

namespace Updateable
{
    struct LoaderSpecification
    {
        std::string name;
        std::string buildPath;
    };

    class Loader
    {
    public:
        Loader(const LoaderSpecification &spec);
        ~Loader();

        void run();

    private:


    private:
        LoaderSpecification m_spec;
    };

    // to be defined by client
    Loader *createLoader();
}