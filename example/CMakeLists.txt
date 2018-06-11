# This part of the project is a collection of examples. This code designed
# to be used stand-alone, hence we are declaring 'project' and calling
# 'HunterGate' here (by including 'init.cmake). When using as a part of parent
# project the 'HunterGate' call effectively will be ignored.

# Project starts here and not inside 'example/fruits/CMakeLists.txt' since
# we have to support '#include <fruits/*.hpp>' pattern. Meaning that
# 'example/fruits/quick_meal' can't be used as a stand-alone project.

# Usage:
#
# * copy 'fruits/example' directory to new location:
#
#     > cp -r fruits/example my-new-fruits-project
#
# * Remove FRUITS_EXAMPLE_GIT_SELF or set it to OFF
#
# * Remove 'add_subdirectory' calls from 'fruits/CMakeLists.txt with
#   uninterested examples

cmake_minimum_required(VERSION 3.2)

# Use 'hunter_config(fruits GIT_SELF)'. If project build as part of 'fruits'
# then 'init.cmake' included by parent and this option set to 'OFF'
# (see 'config.cmake').  If example build as a stand-alone project then option
# will be initialized here and set to 'ON'.
option(FRUITS_EXAMPLE_GIT_SELF "Use GIT_SELF" ON)

# This is where HunterGate called from.
# For rationale see comments inside module.
include("cmake/include/init.cmake")

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
