# https://github.com/ruslo/hunter/wiki/pkg.gtest
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_subdirectory(check_tropical)
add_subdirectory(skin_off)
