add_executable(fruits_breakfast ${FRUITS_BREAKFAST_SOURCES})
target_include_directories(
    fruits_breakfast
    PUBLIC
    "$<BUILD_INTERFACE:${LOCAL_INCLUDE_DIRECTORY}>"
)

target_link_libraries(fruits_breakfast PUBLIC fruits_tropical)

if(NOT IOS)
  install(
      TARGETS fruits_breakfast
      EXPORT "${TARGETS_EXPORT_NAME}"
      LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
      RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
      INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
  )
endif()
