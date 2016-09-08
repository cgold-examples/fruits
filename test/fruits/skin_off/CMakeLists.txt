add_executable(fruits_skin_off ${FRUITS_SKIN_OFF_SOURCES})
target_link_libraries(
    fruits_skin_off GTest::main fruits_tropical fruits_rosaceae
)

add_test(NAME fruits_skin_off COMMAND fruits_skin_off)
