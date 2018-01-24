add_library(fruits_rosaceae ${FRUITS_ROSACEAE_SOURCES})
target_include_directories(fruits_rosaceae PUBLIC ${LOCAL_INCLUDE_DIRECTORY})

install(
    TARGETS fruits_rosaceae
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "include"
)
