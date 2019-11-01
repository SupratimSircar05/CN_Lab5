cmake_minimum_required(VERSION 3.15)
project(CN_Lab5 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CN_Lab5_Q1_c Q1client.c)
add_executable(CN_Lab5_Q1_s Q1server.c)
add_executable(CN_Lab5_Q2_c1 Q2client1.c)
add_executable(CN_Lab5_Q2_c2 Q2client2.c)
add_executable(CN_Lab5_Q2_s Q2server.c)
add_executable(CN_Lab5_Q3_c Q3client.c)
add_executable(CN_Lab5_Q3_s Q3server.c)
