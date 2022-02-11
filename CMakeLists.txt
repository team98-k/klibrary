# Miminum required version of CMake.
cmake_minimum_required(VERSION 3.11)

# Cache variables
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Project info
project(
    klibrary
    VERSION 1.0.0
    DESCRIPTION "klibrary"
    LANGUAGES CXX
)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set variable 'srcPath' to ./src
set(srcPath ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Checking build type
if (CMAKE_BUILD_TYPE STREQUAL "")
    # Build type is not set.
    message(STATUS "Build type was unspecified, set to Release")
    set(CMAKE_BUILD_TYPE Release)
else ()
    message(STATUS "Build type specified as '${CMAKE_BUILD_TYPE}'")
endif ()

# Making debug definition.
if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "_DEBUG")
else ()
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "NDEBUG")
endif ()

# Make library file.
add_library(
    ${PROJECT_NAME}
    STATIC
    ${srcPath}/klibrary.cpp
)

# Set library include directories
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${srcPath}
)

# Compile options.
target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    -Wall
    -Werror
)

# Set start project for Visual Studio.
if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
endif ()

# Making package
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/klibraryConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/klibrary
)

target_include_directories(klibrary
    PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set_property(TARGET klibrary PROPERTY VERSION ${PROJECT_VERSION})
set_property(TARGET klibrary PROPERTY SOVERSION 3)
set_property(TARGET klibrary PROPERTY
  INTERFACE_klibrary_MAJOR_VERSION 3)
set_property(TARGET klibrary APPEND PROPERTY
  COMPATIBLE_INTERFACE_STRING klibrary_MAJOR_VERSION
)

write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/klibraryConfigVersion.cmake"
  VERSION "${version}"
  COMPATIBILITY AnyNewerVersion
)

install(TARGETS klibrary
        EXPORT klibraryTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(FILES src/klibrary.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/klibrary
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/klibraryConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/klibraryConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/klibrary
)

install(EXPORT klibraryTargets
        FILE klibraryTargets.cmake
        NAMESPACE klibrary::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/klibrary
)

export(EXPORT klibraryTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/klibraryTargets.cmake"
       NAMESPACE klibrary::
)