# 需要较新的 CMake 版本以获得更好的 C++ Modules 支持
cmake_minimum_required(VERSION 4.0.0)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

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


# --- C++ Modules 支持 ---
# 对于 GCC (GNU) 编译器，需要添加 -fmodules-ts 标志来启用 C++ Modules
# 使用 target_compile_options 将标志仅应用于此目标
# 使用 $<COMPILE_LANG_AND_ID:CXX,GNU> 的生成器表达式，确保只在用 GCC 编译 C++ 时添加此标志
# target_compile_options(my_app PRIVATE "$<$<COMPILE_LANG_AND_ID:CXX,GNU>:-fmodules>")

# # --- （可选）检查编译器和版本 ---
# # 你可以添加检查来确保使用的是 GCC 15+
# if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
#     if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 15.0) # 检查版本是否低于 15
#          message(WARNING "GCC version ${CMAKE_CXX_COMPILER_VERSION} might have incomplete or unstable support for 'import std;'. GCC 15 or later is recommended.")
#          # 或者，如果严格要求 GCC 15+，可以使用 FATAL_ERROR
#          # message(FATAL_ERROR "GCC 15 or later is required for 'import std;'. Found version ${CMAKE_CXX_COMPILER_VERSION}.")
#     endif()
#     message(STATUS "Using GCC ${CMAKE_CXX_COMPILER_VERSION} with C++ Modules enabled (-fmodules).")
# endif()

# # --- （可选）链接库 ---
# # 对于 `import std;`，通常不需要显式链接标准库（它会被隐式处理），
# # 但如果你的项目依赖其他库，像往常一样使用 target_link_libraries
# # target_link_libraries(my_app PRIVATE some_other_library)

# # --- （可选）CMake 的实验性模块支持 ---
# # CMake 3.28+ 引入了 CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 来尝试自动扫描模块依赖。
# # 对于 `import std;` 来说，依赖是预编译的系统模块，而不是项目内的模块，
# # 所以 `-fmodules-ts` 标志通常是关键。
# # 你可以尝试启用这个实验性特性，看看是否有帮助，但这主要用于处理项目内定义的模块。
# set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1) 
# message(STATUS "CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP is ${CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP}")

# # --- 安装规则（如果需要） ---
# # install(TARGETS my_app DESTINATION bin)