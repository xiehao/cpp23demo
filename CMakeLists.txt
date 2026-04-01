# 需要较新的 CMake 版本以获得更好的 C++ Modules 支持
cmake_minimum_required(VERSION 4.3.0)

# 开启对导入标准库的实验性支持
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")

# 项目名称和语言
project(ImportStdExample LANGUAGES CXX)

# 添加可执行文件目标
add_executable(my_app main.cpp)

# 设置目标属性（支持C++23标准、开启模块支持、关闭编译器扩展以保持标准、为clangd静态解析导出编译命令）
set_target_properties(my_app PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    CXX_MODULE_STD ON
    CXX_EXPORT_COMPILE_COMMANDS ON
)

# 加入标准库实验性支持，解决 Windows/macOS 下标准库的连接错误
if(CMAKE_HOST_WIN32)
    target_link_libraries(my_app stdc++exp)
elseif(CMAKE_HOST_APPLE)
    # TODO
endif()
