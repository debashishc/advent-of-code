cmake_minimum_required(VERSION 3.10)
project(AOC2024)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not set
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src/utils)

# Add utils library
add_library(utils
    src/utils/fileReader.cpp
)

# Function to add daily challenges
function(add_daily_challenge DAY)
    add_executable(day${DAY} src/day${DAY}/day${DAY}.cpp)
    target_link_libraries(day${DAY} utils)
    # Copy input file to build directory
    configure_file(
        ${PROJECT_SOURCE_DIR}/src/day${DAY}/input.txt
        ${PROJECT_BINARY_DIR}/day${DAY}/input.txt
        COPYONLY
    )
endfunction()

# Add days (uncomment as you progress)
add_daily_challenge("01")
# add_daily_challenge("02")
# add_daily_challenge("03")
# ...and so on