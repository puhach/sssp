cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)


project(sssp)

#find_package(Catch2 CONFIG REQUIRED)

add_executable(bruteforce bruteforce.cpp)

add_executable(dijkstra_naive dijkstra_naive.cpp)

add_executable(dijkstra_with_binary_heap dijkstra_with_binary_heap.cpp)

#target_compile_definitions(playground PRIVATE CONFIGURATOR_WINDOW)

#target_include_directories(playground PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(playground PRIVATE  ${OpenCV_LIBS}  ${Boost_LIBRARIES})


if(MSVC)
	set_property(TARGET bruteforce PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
	set_property(TARGET dijkstra_naive PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
	set_property(TARGET dijkstra_with_binary_heap PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()