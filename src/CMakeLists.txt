cmake_minimum_required(VERSION 3.10)

project(MarxMan)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCE_FILES "*.cpp")

add_executable(main ${SOURCE_FILES})

target_include_directories(
	main
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
	)

add_subdirectory(unit_module)

target_link_libraries(main unit_module)
