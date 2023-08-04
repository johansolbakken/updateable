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
    std::cout << "> ";
    std::string input;
    std::cin >> input;
    if (input == "exit")
    {
        Updateable::Application::instance().close();
    }
    else if (input == "restart")
    {
        Updateable::Application::instance().restart();
    }
    else
        std::cout << "Unknown command\n";
}