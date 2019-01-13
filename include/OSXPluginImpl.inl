#pragma once

#ifdef MIST_MAC

#include <Mist_common/include/UtilityMacros.h>
#include "PluginPlatform.h"

#include <dlfcn.h>

MIST_NAMESPACE

namespace Plugin {

    inline Handle Load(const char* pluginDirectory) {

        MIST_ASSERT(pluginDirectory != nullptr);
        return dlopen(pluginDirectory, RTLD_LAZY | RTLD_LOCAL);
    }

    inline void Unload(Handle handle) {

        MIST_ASSERT(handle != nullptr);
        const bool hasFreed = (0 == dlclose(handle));

        // Library has failed to be freed
        MIST_ASSERT(hasFreed);
    }

    template< typename ReturnType, typename... Args >
        API<ReturnType, Args...> GetAPI(Handle handle, const char* apiName) {

            // If this fails Plugin was not loaded or failed to load
            MIST_ASSERT(handle != nullptr);
            return reinterpret_cast< API<ReturnType, Args...> >(dlsym(handle, apiName));
        }
}

MIST_NAMESPACE_END

#endif // MIST_MAC
