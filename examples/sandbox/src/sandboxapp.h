#pragma once

#include <updateable/updateable.h>

class SandboxApp : public Updateable::Application
{
public:
    SandboxApp(const Updateable::ApplicationSpecification &spec);
    ~SandboxApp() override;
};