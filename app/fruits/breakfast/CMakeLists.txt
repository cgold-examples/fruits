set(target_name fruits_breakfast)

add_executable(${target_name} ${FRUITS_BREAKFAST_SOURCES})
target_include_directories(
    ${target_name}
    PUBLIC
    "$<BUILD_INTERFACE:${LOCAL_INCLUDE_DIRECTORY}>"
)

target_link_libraries(${target_name} PUBLIC fruits_tropical)

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
