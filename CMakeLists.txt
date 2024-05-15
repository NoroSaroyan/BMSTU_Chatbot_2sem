cmake_minimum_required(VERSION 3.27.9)
project(BMSTU_Chatbot_2sem)
set(CMAKE_CXX_STANDARD 17)

# Set the Boost root directory to help CMake locate Boost
set(Boost_ROOT "/usr/local/Cellar/boost")

# Find Boost libraries, specifying the required components
find_package(Boost 1.70.0 REQUIRED COMPONENTS system filesystem)

# Include Boost directories
include_directories(${Boost_INCLUDE_DIRS})

# Add the executable with all source files and headers
add_executable(BMSTU_Chatbot_2sem
        main.cpp
        Menu/Menu.h
        Menu/MenuItem.h
        Menu/MenuItem.cpp
        Menu/Menu.cpp
        Entity/user/User.h
        Entity/user/User.cpp
        Encoder.cpp
        service/user/UserService.cpp
        service/user/UserService.h
        Utils/Utilities.cpp
        Utils/user/UserMapper.cpp
        Utils/Utilities.h
        Utils/user/UserMapper.h
        Entity/qa/QA.cpp
        Entity/qa/QA.h
        AuthManager.cpp
        AuthManager.h
        Utils/qa/QAMapper.cpp
        Utils/qa/QAMapper.h
        service/qa/QAService.cpp
        service/qa/QAService.h
        service/history/HistoryService.cpp
        service/history/HistoryService.h
)

# Link against the Boost libraries
target_link_libraries(BMSTU_Chatbot_2sem ${Boost_LIBRARIES})
