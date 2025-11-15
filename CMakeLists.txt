cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)


project(sssp)

#find_package(Catch2 CONFIG REQUIRED)

add_executable(
	sssp 
	main.cpp 
	edge.h 
	bruteforce.h 
	dijkstra_naive.h 
	dijkstra_with_binary_heap.h 
	bruteforce.cpp 
	dijkstra_naive.cpp 
	dijkstra_with_binary_heap.cpp
)

#target_compile_definitions(playground PRIVATE CONFIGURATOR_WINDOW)

#target_include_directories(playground PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(playground PRIVATE  ${OpenCV_LIBS}  ${Boost_LIBRARIES})


if(MSVC)
	set_property(TARGET sssp PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()