#pragma once

#ifdef MIST_WINDOWS

#include <Mist_Common/include/UtilityMacros.h>
#include "PluginPlatform.h"

#include <Windows.h>

MIST_NAMESPACE

namespace Plugin {

	inline Handle Load(const char* pluginDirectory) {

		MIST_ASSERT(pluginDirectory != nullptr);
		return LoadLibrary(pluginDirectory);
	}

	inline void Unload(Handle handle) {

		MIST_ASSERT(handle != nullptr);
		bool hasFreed = FreeLibrary(reinterpret_cast<HMODULE>(handle));
		
		// Library has failed to be freed 
		MIST_ASSERT(hasFreed);
	}

	template< typename ReturnType, typename... Args >
	API<ReturnType, Args...> GetAPI(Handle handle, const char* apiName) {

		// If this fails Plugin was not loaded or failed to load
		MIST_ASSERT(handle != nullptr);
		return reinterpret_cast< API<ReturnType, Args...> >(GetProcAddress((HMODULE)handle, apiName));
	}
}

MIST_NAMESPACE_END

#endif // MIST_WINDOWS