#include <loader/entrypoint.h>

Updateable::Loader *Updateable::createLoader()
{
    Updateable::LoaderSpecification spec;
    spec.name = "sandboxapp";

    return new Updateable::Loader(spec);
}