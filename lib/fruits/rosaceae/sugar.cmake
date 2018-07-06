include(sugar_files)

sugar_files(
    FRUITS_ROSACEAE_SOURCES
    Pear.cpp
    Pear.hpp
    Plum.cpp
    Plum.hpp
    rosaceae.hpp
)

sugar_files(
    FRUITS_SKIN_OFF_SOURCES
    Pear.cpp # TODO: optimize using OBJECTS
)

sugar_include(unittest)
