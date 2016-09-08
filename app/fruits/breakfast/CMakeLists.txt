add_executable(fruits_breakfast ${FRUITS_BREAKFAST_SOURCES})
target_link_libraries(fruits_breakfast fruits_tropical)

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
