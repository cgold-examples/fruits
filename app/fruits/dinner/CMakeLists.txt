add_executable(fruits_dinner ${FRUITS_DINNER_SOURCES})
target_link_libraries(fruits_dinner PUBLIC fruits_rosaceae fruits_tropical)

if(NOT IOS)
  install(
      TARGETS fruits_dinner
      EXPORT "${TARGETS_EXPORT_NAME}"
      LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
      INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  )
endif()
