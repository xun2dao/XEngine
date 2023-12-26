set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE  ENGINE_SRC src/*.cpp)

add_library(engine  ${ENGINE_SRC})
target_include_directories(engine PUBLIC include)
