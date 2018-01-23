if(TARGET fruits_rosaceae)
  add_library(fruits::fruits_rosaceae ALIAS fruits_rosaceae)
  add_library(fruits::fruits_tropical ALIAS fruits_tropical)
else()
  # For the real project 'hunter_add_package' should be called before:
  # hunter_add_package(fruits)

  find_package(fruits CONFIG REQUIRED)
endif()

add_executable(fruits_vegan_party ${FRUITS_VEGAN_PARTY_SOURCES})
target_link_libraries(
    fruits_vegan_party
    PUBLIC
    fruits::fruits_rosaceae
    fruits::fruits_tropical
)
