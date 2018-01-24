add_library(fruits_tropical ${FRUITS_TROPICAL_SOURCES})
target_include_directories(
    fruits_tropical
    PUBLIC
    "$<BUILD_INTERFACE:${LOCAL_INCLUDE_DIRECTORY}>"
    "$<BUILD_INTERFACE:${LOCAL_GENERATED_INCLUDE_DIRECTORY}>"
)

# Renaming because:
# * We need prefix '${PROJECT_NAME}' to fit OSX/iOS frameworks layout
# * File name match name of the macro
set(
    export_header
    "${LOCAL_GENERATED_INCLUDE_DIRECTORY}/${PROJECT_NAME}/FRUITS_TROPICAL_EXPORT.h"
)
include(GenerateExportHeader)
generate_export_header(fruits_tropical EXPORT_FILE_NAME ${export_header})

install(
    TARGETS fruits_tropical
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "include"
)

install(FILES ${export_header} DESTINATION "include/${PROJECT_NAME}")
