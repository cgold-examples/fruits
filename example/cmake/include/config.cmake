# Tweak third party package.
option(FRUITS_GTEST_WITH_FOO "Add WITH_FOO=ON to GTest build" ON)

if(FRUITS_GTEST_WITH_FOO)
  set(gtest_args WITH_FOO=ON)
else()
  set(gtest_args "")
endif()

# Third party tuning:
# * https://github.com/ruslo/hunter/wiki/example.custom.config.id
# NOTE: this particular line doesn't change anything, it's just an example
hunter_config(GTest VERSION ${HUNTER_GTest_VERSION} CMAKE_ARGS ${gtest_args})

# This option will be ON only if we are buildling 'fruits/example' as a
# stand-alone project. In this case parent 'fruits' project will be packed by
# git and installed as regular Hunter package when 'hunter_add_package(fruits)'
# called.
option(FRUITS_GIT_SELF "Use GIT_SELF" OFF)
if(FRUITS_GIT_SELF)
  hunter_config(fruits GIT_SELF)
endif()
