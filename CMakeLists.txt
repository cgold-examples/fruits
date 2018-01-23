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
    URL "https://github.com/ruslo/hunter/archive/v0.19.233.tar.gz"
    SHA1 "248462b5a67b90d38534351fd83c2ad1977f0fef"
    LOCAL # Load cmake/Hunter/config.cmake (optional, usually not required)
)

# Now the project can be started
project(fruits VERSION 1.0.0)

# https://docs.hunter.sh/en/latest/packages/pkg/sugar.html
hunter_add_package(sugar)
find_package(sugar CONFIG REQUIRED)

# Collect sources {
# * https://github.com/ruslo/sugar/wiki/Collecting-sources

sugar_include(lib)
sugar_include(app)

# Folder 'test' have no sources. All sources for GTest located in 'lib' folder.
# Sugar will collect only data files for testing.
sugar_include(test)

# Do not dive into 'example' folder. Projects can be used stand-alone
# hence should collect sources themself.

# }

# http://cgold.readthedocs.io/en/latest/tutorials/cmake-sources/includes.html#modify-correct
# TODO: add CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# If somebody want to install your libraries and tools probably they don't want
# to build tests or examples:
# * https://github.com/ruslo/hunter/wiki/usr.adding.new.package#cmake-options
# Prefix options with project name:
# * http://cgold.readthedocs.io/en/latest/tutorials/variables/cache.html#recommendation
option(FRUITS_BUILD_EXAMPLES "Build examples" ON)
option(FRUITS_BUILD_TESTS "Build tests" ON)

# All targets from this project use those include directories
include_directories("${CMAKE_CURRENT_LIST_DIR}/lib")

### Installation (https://github.com/forexample/package-example) {

set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

include(CMakePackageConfigHelpers)

# Note: PROJECT_VERSION is used as a VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Use variables:
#   * TARGETS_EXPORT_NAME
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/Config.cmake.in"
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
