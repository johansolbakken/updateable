#include "sandboxlayer.h"

#include <iostream>

std::string version = "0.0.1";

void SandboxLayer::onAttach()
{
    std::cout << "SandboxApp Version: " << version << "\n";
}

void SandboxLayer::onDetach()
{
}

void SandboxLayer::onUpdate()
{
    static bool first = true;
    if (first)
    {
        std::cout << "SandboxLayer::onUpdate()\n";
        first = false;
    }
}