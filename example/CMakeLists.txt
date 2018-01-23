# This part of the project is a collection of examples. This code designed
# to be used stand-alone, hence we are declaring 'project' and calling
# 'HunterGate' here. When using as a part of parent project the 'HunterGate' call
# effectively will be ignored.

# Project starts here and not inside 'example/fruits/CMakeLists.txt' since
# we have to support '#include <fruits/*.hpp>' pattern. Meaning that
# 'example/fruits/quick_meal' can't be used as a stand-alone project.

# The idea is to allow user to copy this file, remove 'add_subdirectory'
# directives with uninterested examples, copy sources for the 'add_subdirectory'
# that left.

cmake_minimum_required(VERSION 3.1)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.233.tar.gz"
    SHA1 "248462b5a67b90d38534351fd83c2ad1977f0fef"
)

# We are not installing anything hence the name of the project doesn't matter.
# There will be no corresponding 'fruits-example' C++ namespace.
project(fruits-example)

# https://docs.hunter.sh/en/latest/packages/pkg/sugar.html
hunter_add_package(sugar)
find_package(sugar CONFIG REQUIRED)

# Collect sources:
# * https://github.com/ruslo/sugar/wiki/Collecting-sources
sugar_include(fruits)

add_subdirectory(fruits)
