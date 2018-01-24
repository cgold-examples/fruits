# Must be the first command:
# * http://cgold.readthedocs.io/en/latest/tutorials/version-policies.html#cmake-minimum-required
cmake_minimum_required(VERSION 3.1)

# Hunter options {

# **Before** HunterGate and must be set to cache **without** FORCE (meaning
# without INTERNAL, since INTERNAL implies FORCE) to allow customization
# from outside:
# * http://cgold.readthedocs.io/en/latest/tutorials/variables/cache.html#use-case
option(HUNTER_STATUS_DEBUG "Print debug info" ON)

# Not needed, this is default. Added as an example.
option(HUNTER_ENABLED "Enable Hunter package manager" ON)

# }

# Include HunterGate:
# * https://docs.hunter.sh/en/latest/quick-start/boost-components.html#first-step
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.234.tar.gz"
    SHA1 "3deec1041bd01c91e78269522b901fbab3a765e5"
    LOCAL # Load cmake/Hunter/config.cmake (optional, usually not required)
)

# Now the project can be started
project(fruits VERSION 1.0.0)

# https://docs.hunter.sh/en/latest/packages/pkg/check_ci_tag.html
hunter_add_package(check_ci_tag)
find_package(check_ci_tag CONFIG REQUIRED)

# Check version project matches tag from continuous integration build
check_ci_tag()

# Project options {

# Should be before collecting sources (some sources can be optional).

# If somebody want to install your libraries and tools probably they don't want
# to build tests or examples:
# * https://docs.hunter.sh/en/latest/creating-new/create/cmake.html#cmake-options
# Prefix options with project name:
# * http://cgold.readthedocs.io/en/latest/tutorials/variables/cache.html#recommendation
option(FRUITS_BUILD_EXAMPLES "Build examples" ON)
option(FRUITS_BUILD_TESTS "Build tests" ON)

# }

# https://docs.hunter.sh/en/latest/packages/pkg/sugar.html
hunter_add_package(sugar)
find_package(sugar CONFIG REQUIRED)

# Collect sources {
# * https://github.com/ruslo/sugar/wiki/Collecting-sources

sugar_include(lib/fruits)
sugar_include(app/fruits)

# Folder 'test' have no sources. All sources for GTest located in 'lib' folder.
# Sugar will collect only data files for testing.
sugar_include(test/fruits)

# Do not dive into 'example' folder. Projects can be used stand-alone
# hence should collect sources themself.

# }

# http://cgold.readthedocs.io/en/latest/tutorials/cmake-sources/includes.html#modify-correct
# TODO: add CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/module")

### Installation (https://github.com/forexample/package-example) {

set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

# Use:
# * PROJECT_VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Use:
# * TARGETS_EXPORT_NAME
# * PROJECT_NAME
configure_package_config_file(
    "cmake/template/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

install(
    DIRECTORY "lib/fruits"
    DESTINATION "include"
    FILES_MATCHING
    PATTERN "*.hpp"
    PATTERN "/unittest/" EXCLUDE
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)

### }

### RPATH settings {

if(BUILD_SHARED_LIBS)
  # https://cmake.org/Wiki/CMake_RPATH_handling
  if(IOS)
    # TODO: iOS dynamic framework
  elseif(ANDROID)
    # *.so libraries loaded by Java code, RPATH will not be used
  elseif(UNIX)
    # Executables installed to 'bin' folder, shared libraries to 'lib' folder:
    #   <root>/bin/<executable>
    #   <root>/lib/<library>
    # Path from executable to library: <executable-path>/../lib

    # To test this code install project with BUILD_SHARED_LIBS=ON and try to
    # run any executable from 'bin' folder, e.g.:
    #   /<install-root>/bin/fruits_breakfast

    # If RPATH is not correct, you will see the error:
    #   fruits_breakfast: error while loading shared libraries:
    #   libfruits_tropical.so: cannot open shared object file:
    #   No such file or directory
    if(APPLE)
      # https://developer.apple.com/legacy/library/documentation/Darwin/Reference/ManPages/man1/dyld.1.html
      set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
    else()
      # https://linux.die.net/man/8/ld-linux
      set(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
    endif()
  endif()
endif()

### }

set(
    LOCAL_GENERATED_INCLUDE_DIRECTORY
    "${CMAKE_CURRENT_BINARY_DIR}/generated_headers"
)

add_subdirectory(lib)
add_subdirectory(app)

if(FRUITS_BUILD_TESTS)
  if(ANDROID OR IOS)
    # TODO: Testing on simulators (devices?)
  else()
    enable_testing() # Should be in top-level CMakeLists.txt
  endif()
  add_subdirectory(test)
endif()

if(FRUITS_BUILD_EXAMPLES)
  add_subdirectory(example)
endif()
