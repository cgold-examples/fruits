cmake_minimum_required(VERSION 3.1)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.15.23.tar.gz"
    SHA1 "ab53ab9ede1cba3b894ed9e17a26f091924f6d65"
)

project(fruits_vegan_party)

# https://github.com/ruslo/hunter/wiki/pkg.sugar
hunter_add_package(Sugar)
include("${SUGAR_ROOT}/cmake/Sugar")
include(sugar_include)

# Collect sources:
# * https://github.com/ruslo/sugar/wiki/Collecting-sources
sugar_include("./")

if(TARGET fruits_rosaceae)
  add_library(fruits::fruits_rosaceae ALIAS fruits_rosaceae)
  add_library(fruits::fruits_tropical ALIAS fruits_tropical)
else()
  find_package(fruits CONFIG REQUIRED)
endif()

add_executable(fruits_vegan_party ${FRUITS_VEGAN_PARTY_SOURCES})
target_link_libraries(
    fruits_vegan_party
    fruits::fruits_rosaceae
    fruits::fruits_tropical
)
