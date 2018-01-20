cmake_minimum_required(VERSION 3.1)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.232.tar.gz"
    SHA1 "a412c45fe4c5a72fed386f62dd8d753bd4fd3d11"
)

project(fruits_quick_meal)

# https://github.com/ruslo/hunter/wiki/pkg.sugar
hunter_add_package(Sugar)
include("${SUGAR_ROOT}/cmake/Sugar")
include(sugar_include)

# Collect sources:
# * https://github.com/ruslo/sugar/wiki/Collecting-sources
sugar_include("./")

if(TARGET fruits_rosaceae)
  add_library(fruits::fruits_rosaceae ALIAS fruits_rosaceae)
else()
  find_package(fruits CONFIG REQUIRED)
endif()

add_executable(fruits_quick_meal ${FRUITS_QUICK_MEAL_SOURCES})
target_link_libraries(fruits_quick_meal fruits::fruits_rosaceae)
