set(target_name fruits_dinner)

add_executable(${target_name} ${FRUITS_DINNER_SOURCES})
target_link_libraries(${target_name} PUBLIC fruits_rosaceae fruits_tropical)

if(NOT IOS)
  install(
      TARGETS ${target_name}
      EXPORT "${TARGETS_EXPORT_NAME}"
      LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
      INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  )
endif()
