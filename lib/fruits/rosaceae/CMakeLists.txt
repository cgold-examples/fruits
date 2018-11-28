add_library(fruits_rosaceae ${FRUITS_ROSACEAE_SOURCES})
target_include_directories(
    fruits_rosaceae
    PUBLIC
    "$<BUILD_INTERFACE:${LOCAL_INCLUDE_DIRECTORY}>"
    "$<BUILD_INTERFACE:${LOCAL_GENERATED_INCLUDE_DIRECTORY}>"
)

# ALIAS target allow us to have same interface while including project
# * by `add_subdirectory(3rdParty/fruits)`
# * by `find_package(fruits CONFIG REQUIRED)`
add_library(${NAMESPACE}fruits_rosaceae ALIAS fruits_rosaceae)

# Renaming because:
# * We need prefix '${PROJECT_NAME}' to fit OSX/iOS frameworks layout
# * File name match name of the macro
set(
    export_header
    "${LOCAL_GENERATED_INCLUDE_DIRECTORY}/${PROJECT_NAME}/FRUITS_ROSACEAE_EXPORT.h"
)
include(GenerateExportHeader)
generate_export_header(fruits_rosaceae EXPORT_FILE_NAME ${export_header})

install(
    TARGETS fruits_rosaceae
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(
    FILES ${export_header}
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}"
)
