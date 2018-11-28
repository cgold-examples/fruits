set(target_name fruits_check_tropical)

add_executable(${target_name} ${FRUITS_CHECK_TROPICAL_SOURCES})
target_link_libraries(${target_name} PUBLIC GTest::main fruits_tropical)

foreach(x ${FRUITS_CHECK_TROPICAL_DATA})
  # Copy file(s) to the working directory of the test
  add_custom_command(
      TARGET ${target_name}
      PRE_BUILD
      COMMAND "${CMAKE_COMMAND}" -E copy ${x} ${CMAKE_CURRENT_BINARY_DIR}
  )
endforeach()

add_test(NAME ${target_name} COMMAND ${target_name})

if(WIN32 OR CYGWIN)
  # If dependent library is a DLL we have to add location of DLL to PATH
  set(new_path "")
  foreach(target fruits_tropical)
    list(APPEND new_path $<TARGET_FILE_DIR:${target}>)
  endforeach()
  list(APPEND new_path $ENV{PATH})

  if(WIN32)
    string(REPLACE ";" "\;" new_path "${new_path}")
  elseif(CYGWIN)
    string(REPLACE ";" ":" new_path "${new_path}")
  else()
    message(FATAL_ERROR "Unreachable")
  endif()

  set_tests_properties(
      ${target_name} PROPERTIES ENVIRONMENT "PATH=${new_path}"
  )
endif()
