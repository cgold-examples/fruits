add_executable(fruits_skin_off ${FRUITS_SKIN_OFF_SOURCES})
target_link_libraries(
    fruits_skin_off PUBLIC GTest::main fruits_tropical fruits_rosaceae
)

add_test(NAME fruits_skin_off COMMAND fruits_skin_off)

if(WIN32 OR CYGWIN)
  # If dependent library is a DLL we have to add location of DLL to PATH
  set(new_path "")
  foreach(target fruits_tropical fruits_rosaceae)
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
      fruits_skin_off PROPERTIES ENVIRONMENT "PATH=${new_path}"
  )
endif()
