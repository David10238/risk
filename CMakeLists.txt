cmake_minimum_required(VERSION 3.0.0)
project(risk VERSION 0.1.0)

add_executable(risk 
    main.cpp
    src/graphics.cpp
    src/image.cpp
    src/board.cpp
)

target_link_libraries(risk SDL2main SDL2 SDL2_image)
