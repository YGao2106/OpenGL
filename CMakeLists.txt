cmake_minimum_required(VERSION 3.20)


project(openGL)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libraries/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_compile_options(-g -Wall)
file(GLOB sourcefiles ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(openGL ${sourcefiles})

target_link_directories(openGL PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libraries/lib)



target_link_libraries(openGL PUBLIC glfw3 opengl32 glew32)
