cmake_minimum_required(VERSION 3.27.8)
project(BMSTU_Chatbot_2sem)
set(CMAKE_CXX_STANDARD 17)
add_executable(BMSTU_Chatbot_2sem main.cpp
        Menu/Menu.h
        Menu/MenuItem.h
        Headers.h
        Headers.h
        Menu/MenuItem.cpp
        Menu/Menu.cpp
        User/User.h
        Headers.h
        User/User.cpp
        Encoder.cpp
        User/UserServices.cpp
        Utils/Utilities.cpp
        Utils/Mapper.cpp
        User/UserServices.h
        Utils/Mapper.h
        Utils/Utilities.h)

