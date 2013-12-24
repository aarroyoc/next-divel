/**
* @file ND_Version.hpp
* @author Adrián Arroyo Calle
* @brief Defines the version constants
* ND_Versions.hpp defines the version of the kernel and the operating system
*/
#ifndef ND_VERSION_HPP
#define ND_VERSION_HPP

/**
* @brief The codename of the OS version
*/
#define NEXT_DIVEL_CODENAME "Aurora"

/**
* @brief The name of the NextDivel distro
*/
#define NEXT_DIVEL_DISTRO "NextDivel"

/**
* @brief The year of the OS
*/
#define NEXT_DIVEL_YEAR "2013"

/**
* @brief The vendor of the OS
*/
#define NEXT_DIVEL_VENDOR "Adrián Arroyo Calle"

/**
* @brief The releases of NextDivel
*/
#define NEXT_DIVEL_VERSION_MAJOR 0
#define NEXT_DIVEL_VERSION_MINOR 3
#define NEXT_DIVEL_VERSION_PATCH 0
/**
* @brief The current arch of NextDivel
*/
#define NEXT_DIVEL_ARCH "x86"
/**
* @brief 64 bits? Experimental
*/
#if (__SIZEOF_POINTER__ == 8)
#define NEXT_DIVEL_64
#else
#define NEXT_DIVEL_32
#endif
/**
* @brief Itanium? Experimental
*/
#if __ia64
#define NEXT_DIVEL_ITANIUM
#endif
/**
* @brief PowerPC? Experimental
*/
#if __powerpc__
#define NEXT_DIVEL_PPC
#endif
/**
* @brief SPARC? Experimental
*/
#if __sparc
#define NEXT_DIVEL_SPARC
#endif

/**
* @brief i386? Experimental
*/
#if __i386
#define NEXT_DIVEL_I386
#endif

/**
* @brief x86_64? Experimental
*/
#if __x86_64
#define NEXT_DIVEL_X86_64
#endif

/**
* @brief The current line
*/
#define NEXT_DIVEL_LINE __LINE__

/**
* @brief The current file
*/
#define NEXT_DIVEL_FILE __FILE__

/**
* @brief The current function
*/
#define NEXT_DIVEL_FUNCTION __func__
#endif
