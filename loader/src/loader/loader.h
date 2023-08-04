#pragma once

#include <string>

namespace Updateable
{
    struct LoaderSpecification
    {
        std::string name;
    };

    class Loader
    {
    public:
        Loader(const LoaderSpecification &spec);
        ~Loader();

        void run();

    private:
        LoaderSpecification m_spec;
    };

    // to be defined by client
    Loader *createLoader();
}