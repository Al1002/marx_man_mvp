file(GLOB SOURCE_FILES "*.cpp")

add_library(unit_module ${SOURCE_FILES})

target_include_directories(
    unit_module
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )

add_subdirectory(game_layer_module)

add_subdirectory(graphics_module)
    
target_link_libraries(unit_module game_layer_module graphics_module)
    
    