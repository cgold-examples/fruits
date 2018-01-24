add_executable(fruits_breakfast ${FRUITS_BREAKFAST_SOURCES})
target_include_directories(fruits_breakfast PUBLIC ${LOCAL_INCLUDE_DIRECTORY})

target_link_libraries(fruits_breakfast PUBLIC fruits_tropical)

if(NOT IOS)
  install(
      TARGETS fruits_breakfast
      EXPORT "${TARGETS_EXPORT_NAME}"
      LIBRARY DESTINATION "lib"
      ARCHIVE DESTINATION "lib"
      RUNTIME DESTINATION "bin"
      INCLUDES DESTINATION "include"
  )
endif()
