add_executable(fruits_dinner ${FRUITS_DINNER_SOURCES})
target_link_libraries(fruits_dinner PUBLIC fruits_rosaceae fruits_tropical)

if(NOT IOS)
  install(
      TARGETS fruits_dinner
      EXPORT "${TARGETS_EXPORT_NAME}"
      LIBRARY DESTINATION "lib"
      ARCHIVE DESTINATION "lib"
      RUNTIME DESTINATION "bin"
      INCLUDES DESTINATION "include"
  )
endif()
