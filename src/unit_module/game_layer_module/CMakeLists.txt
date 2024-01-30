file(GLOB SOURCE_FILES "*.cpp")

add_library(game_layer_module ${SOURCE_FILES})

target_include_directories(
    game_layer_module
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )