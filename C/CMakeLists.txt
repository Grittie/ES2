cmake_minimum_required(VERSION 3.10)
project(MissileDefenseSystem C)

set(CMAKE_C_STANDARD 11)

add_executable(main ../main.c ../utilities.c ../periodic_tasks.c)

target_link_libraries(main m rt)  # Link the math library if needed


# Add other necessary libraries if required
