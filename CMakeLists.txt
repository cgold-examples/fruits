# Must be the first command:
# * http://cgold.readthedocs.io/en/latest/tutorials/version-policies.html#cmake-minimum-required
cmake_minimum_required(VERSION 3.1)

# Include HunterGate:
# * https://docs.hunter.sh/en/latest/quick-start/boost-components.html#first-step
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.15.23.tar.gz"
    SHA1 "ab53ab9ede1cba3b894ed9e17a26f091924f6d65"
)

project(fruits)
