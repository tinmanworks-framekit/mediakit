cmake_minimum_required(VERSION 3.23)

project(mediakit VERSION 0.1.0 LANGUAGES C CXX)

option(MEDIAKIT_BUILD_TESTS "Build mediakit tests" ON)
option(MEDIAKIT_ENABLE_INSTALL "Enable install and package export rules" ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(mediakit_core STATIC
    src/media_session.cpp
)
add_library(MediaKit::Core ALIAS mediakit_core)
set_target_properties(mediakit_core PROPERTIES EXPORT_NAME Core)

target_include_directories(mediakit_core
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_features(mediakit_core PUBLIC cxx_std_20)

if(MEDIAKIT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(MEDIAKIT_ENABLE_INSTALL)
    install(
        TARGETS mediakit_core
        EXPORT mediakitTargets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    )

    install(
        DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    install(
        EXPORT mediakitTargets
        FILE mediakitTargets.cmake
        NAMESPACE MediaKit::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mediakit
    )

    configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/mediakitConfig.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/mediakitConfig.cmake
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mediakit
    )

    write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/mediakitConfigVersion.cmake
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )

    install(
        FILES
            ${CMAKE_CURRENT_BINARY_DIR}/mediakitConfig.cmake
            ${CMAKE_CURRENT_BINARY_DIR}/mediakitConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/mediakit
    )
endif()
