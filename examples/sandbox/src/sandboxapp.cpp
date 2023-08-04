#include "sandboxapp.h"

SandboxApp::SandboxApp(const Updateable::ApplicationSpecification &spec)
    : Updateable::Application(spec)
{
}

SandboxApp::~SandboxApp()
{
}

extern "C" Updateable::Application* createApplication()
{
    Updateable::ApplicationSpecification spec;
    spec.name = "Sandbox";
    return new SandboxApp(spec);
}