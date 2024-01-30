cmake_minimum_required(VERSION 3.10)

project(MarxMan)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main main.cpp)

add_subdirectory(unit_module)

target_include_directories(
	main
	PRIVATE
	${CMAKE_CURENT_SOURCE_DIR}
	)

target_link_libraries(main unit_module)
