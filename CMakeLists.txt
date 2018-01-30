cmake_minimum_required(VERSION 3.8)
project(Cryptic)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c cyphers/caesar.c cyphers/vigenere.c cyphers/auto.c cyphers/playfair.c cyphers/railfence.c utils.c constants.c)
set(HEADER_FILES includes/caesar.h includes/vigenere.h includes/auto.h includes/playfair.h includes/railfence.h utils.h constants.h)
add_executable(Cryptic ${SOURCE_FILES})