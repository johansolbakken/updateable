#include "dylib.h"

#include <iostream>

#include <dlfcn.h>

namespace Updateable
{
    Dylib::Dylib(const std::string &name)
    {
        m_handle = dlopen(name.c_str(), RTLD_LAZY);
        if (!m_handle)
        {
            std::cout << "Could not load dylib\n";
            m_handle = nullptr;
            return;
        }
    }

    Dylib::~Dylib()
    {
        if (m_handle)
            dlclose(m_handle);

        m_handle = nullptr;
    }

    void *Dylib::getVoidSymbol(const std::string &name)
    {
        if (!m_handle)
            return nullptr;
        return dlsym(m_handle, name.c_str());
    }
}