#pragma once

#include <iostream>

namespace Updateable
{
    class Dylib
    {
    public:
        Dylib(const std::string &name);
        ~Dylib();

        template <typename T>
        T getSymbol(const std::string &name)
        {
            auto symbol = getVoidSymbol(name);

            if (!symbol)
            {
                std::cout << "Could not load symbol " << name << "\n";
                return nullptr;
            }

            return reinterpret_cast<T>(symbol);
        }

    private:
        void *getVoidSymbol(const std::string &name);

    private:
        void *m_handle;
    };
}