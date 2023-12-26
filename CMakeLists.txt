cmake_minimum_required(VERSION 3.22)
add_subdirectory(engine)
add_subdirectory(sandbox)

target_link_libraries(sandbox PUBLIC engine)
project(
    xengine 
    LANGUAGES C CXX 
    )