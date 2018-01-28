cmake_minimum_required(VERSION 3.8)
project(Cryptic)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c cyphers/caesar.c includes/caesar.h cyphers/vigenere.c includes/vigenere.h cyphers/auto.c includes/auto.h cyphers/playfair.c includes/playfair.h cyphers/railfence.c includes/railfence.h utils.c utils.h)
add_executable(Cryptic ${SOURCE_FILES})