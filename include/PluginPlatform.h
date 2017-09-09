#pragma once

#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN32__) || defined(__WINDOWS__)

#define MIST_WINDOWS 1

#elif defined (__ANDROID__)

#define MIST_ANDROID 1

#elif defined(__linux__) || defined(__linux) || defined(linux)

#define MIST_LINUX 1

#elif defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))

#define MIST_MAC 1

#else

static_assert(false, "Current platform not supported!");

#endif