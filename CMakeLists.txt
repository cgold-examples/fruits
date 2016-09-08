# Must be the first command:
# * http://cgold.readthedocs.io/en/latest/tutorials/version-policies.html#cmake-minimum-required
cmake_minimum_required(VERSION 3.1)

# Include HunterGate:
# * https://docs.hunter.sh/en/latest/quick-start/boost-components.html#first-step
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.15.23.tar.gz"
    SHA1 "ab53ab9ede1cba3b894ed9e17a26f091924f6d65"
    LOCAL # Load cmake/Hunter/config.cmake
)

project(fruits)

# https://github.com/ruslo/hunter/wiki/pkg.sugar
hunter_add_package(Sugar)
include("${SUGAR_ROOT}/cmake/Sugar")
include(sugar_include)

# Collect sources:
# * https://github.com/ruslo/sugar/wiki/Collecting-sources
sugar_include("./")

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
