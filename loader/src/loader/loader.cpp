#include "loader.h"

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
        while (true)
            ;
    }
}