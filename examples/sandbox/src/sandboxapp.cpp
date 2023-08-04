#include <updateable/updateable.h>

#include "sandboxlayer.h"

class SandboxApp : public Updateable::Application
{
public:
    SandboxApp(const Updateable::ApplicationSpecification &spec)
        : Updateable::Application(spec)
    {
        pushLayer(new SandboxLayer());
    }

    ~SandboxApp() override
    {
    }
};

extern "C" Updateable::Application *createApplication()
{
    Updateable::ApplicationSpecification spec;
    spec.name = "Sandbox";
    return new SandboxApp(spec);
}