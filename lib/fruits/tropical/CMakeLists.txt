add_library(fruits_tropical ${FRUITS_TROPICAL_SOURCES})

install(
    TARGETS fruits_tropical
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "include"
)
