add_executable(fruits_check_tropical ${FRUITS_CHECK_TROPICAL_SOURCES})
target_link_libraries(fruits_check_tropical PUBLIC GTest::main fruits_tropical)

foreach(x ${FRUITS_CHECK_TROPICAL_DATA})
  # Copy file(s) to the working directory of the test
  add_custom_command(
      TARGET fruits_check_tropical
      PRE_BUILD
      COMMAND "${CMAKE_COMMAND}" -E copy ${x} ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()

add_test(NAME fruits_check_tropical COMMAND fruits_check_tropical)

if(WIN32 AND BUILD_SHARED_LIBS)
  # If dependent library is a DLL we have to add location of DLL to PATH
  set(new_path "")
  foreach(target fruits_tropical)
    list(APPEND new_path $<TARGET_FILE_DIR:${target}>)
  endforeach()
  list(APPEND new_path $ENV{PATH})

  string(REPLACE ";" "\;" new_path "${new_path}")

  set_tests_properties(
      fruits_check_tropical PROPERTIES ENVIRONMENT "PATH=${new_path}"
  )
endif()
