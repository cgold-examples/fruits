# https://docs.hunter.sh/en/latest/packages/pkg/GTest.html
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

add_subdirectory(check_tropical)
add_subdirectory(skin_off)
