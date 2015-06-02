cmake_minimum_required(VERSION 2.8.3)
project(era-test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# ----------------------------------------------------------------------------------------------------
#     TESTS
# ----------------------------------------------------------------------------------------------------

find_package(OpenCV REQUIRED)
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(test_config test/test_config.cpp)
target_link_libraries(test_config era_config)

add_executable(test_rasterizer test/test_rasterizer.cpp)
target_link_libraries(test_rasterizer era_geometry ${OpenCV_LIBS})

add_executable(test_io test/test_io.cpp)
target_link_libraries(test_io era_io ${OpenCV_LIBRARIES})

add_executable(test_blackboard test/test_blackboard.cpp)
#target_link_libraries(test_blackboard era_blackboard)
