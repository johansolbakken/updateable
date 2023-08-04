#pragma once

namespace Updateable
{
    class Layer
    {
    public:
        Layer() = default;
        virtual ~Layer() = default;

        virtual void onAttach() = 0;
        virtual void onDetach() = 0;
        virtual void onUpdate() {}
    };
}