add_library(fruits_tropical ${FRUITS_TROPICAL_SOURCES})
target_include_directories(fruits_tropical PUBLIC ${LOCAL_INCLUDE_DIRECTORY})

install(
    TARGETS fruits_tropical
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "include"
)
