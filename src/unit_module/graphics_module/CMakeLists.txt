file(GLOB SOURCE_FILES "*.cpp")

add_library(graphics_module ${SOURCE_FILES})

target_link_libraries(graphics_module SDL2 SDL2main)

target_include_directories(
    graphics_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )