add_executable(fruits_check_tropical ${FRUITS_CHECK_TROPICAL_SOURCES})
target_link_libraries(fruits_check_tropical PUBLIC GTest::main fruits_tropical)

foreach(x ${FRUITS_CHECK_TROPICAL_DATA})
  add_custom_command(
      TARGET fruits_check_tropical
      PRE_BUILD
      COMMAND "${CMAKE_COMMAND}" -E copy ${x} ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()

add_test(NAME fruits_check_tropical COMMAND fruits_check_tropical)
