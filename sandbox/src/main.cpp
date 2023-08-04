#include <loader/entrypoint.h>

Updateable::Loader *Updateable::createLoader()
{
    Updateable::LoaderSpecification spec;
    spec.name = "Sandbox";

    return new Updateable::Loader(spec);
}