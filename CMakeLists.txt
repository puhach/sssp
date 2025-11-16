cmake_minimum_required(VERSION 3.14)

project(sssp)

set(CMAKE_CXX_STANDARD 17)

# Enable FetchContent
include(FetchContent)

# Disable Benchmark's internal tests that require GoogleTest
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable benchmark tests" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "Disable GTest tests" FORCE)
set(BENCHMARK_USE_BUNDLED_GTEST OFF CACHE BOOL "" FORCE)

# Enable library optimizations
set(BENCHMARK_ENABLE_LTO ON CACHE BOOL "Enable link time optimization" FORCE)


# Fetch Google Benchmark
FetchContent_Declare(
  benchmark
  GIT_REPOSITORY https://github.com/google/benchmark.git
  GIT_TAG v1.9.4          # Pick a release tag or main; optional but recommended
)


FetchContent_MakeAvailable(benchmark)

find_package(Threads REQUIRED)


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

add_executable(
	sssp_benchmarks	
	benchmarks.cpp
)


# Link Google Benchmark and the threading library (Threads::Threads maps to 
# the correct threading library on each platform)
target_link_libraries(
	sssp_benchmarks
	PRIVATE benchmark::benchmark benchmark::benchmark_main Threads::Threads
)



#target_compile_definitions(playground PRIVATE CONFIGURATOR_WINDOW)

#target_include_directories(playground PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(playground PRIVATE  ${OpenCV_LIBS}  ${Boost_LIBRARIES})


if(MSVC)
	set_property(TARGET sssp PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
endif()