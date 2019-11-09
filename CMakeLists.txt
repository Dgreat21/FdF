cmake_minimum_required(VERSION 3.12.3)
project(fdf)

add_custom_target(fdf
        COMMAND make
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(.:libft:/usr/local/include)
find_library(OPEN_GL OpenGl)
find_library(APP_KIT AppKit)
link_libraries(mlx)

add_executable(f
        debug.c
        draw_lines.c
        events.c
        events_bonus.c
        fdf.c
        handler.c
        lines.c
        main.c
        projection.c
        rotation.c
        struct.c)

add_compile_options(-Wall -Wextra -Werror)

add_subdirectory(libft)

target_link_libraries(f ft mlx ${OPEN_GL} ${APP_KIT})