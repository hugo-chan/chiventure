add_library(common
            src/ctx.c
            src/load_objects.c
            src/sample_game.c)

target_include_directories(common PRIVATE src/)

target_link_libraries(common cli)






