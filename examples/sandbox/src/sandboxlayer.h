#pragma once

#include <updateable/updateable.h>

class SandboxLayer : public Updateable::Layer
{
public:
    ~SandboxLayer() = default;

    void onAttach() override;
    void onDetach() override;
    void onUpdate() override;
};