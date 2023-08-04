#include <loader/entrypoint.h>

Updateable::Loader *Updateable::createLoader()
{
    Updateable::LoaderSpecification spec;
    spec.srcPath = "/Users/johansolbakken/dev/updateable";
    spec.name = "sandboxapp";

    return new Updateable::Loader(spec);
}