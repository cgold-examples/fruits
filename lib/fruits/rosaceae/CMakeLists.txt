add_library(fruits_rosaceae ${FRUITS_ROSACEAE_SOURCES})

install(
    TARGETS fruits_rosaceae
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "include"
)
