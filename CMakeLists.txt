# 需要较新的 CMake 版本以获得更好的 C++ Modules 支持
cmake_minimum_required(VERSION 4.3.0)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

# 项目名称和语言
project(ImportStdExample LANGUAGES CXX)

# 添加可执行文件目标
add_executable(my_app main.cpp)

set_target_properties(my_app PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_MODULE_STD ON
    CXX_EXPORT_COMPILE_COMMANDS ON
)