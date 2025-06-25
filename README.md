# C++23实例：import std;

## 配置工程

以下命令在项目根目录新建`build`文件夹，并将编译产生的所有文件置于此处；采用Ninja作为组织工具（其他工具暂不支持）；采用GCC15作为编译器：
``` shell
cmake -S . -B build -G Ninja -D CMAKE_CXX_COMPILER=g++-15
```

## 编译工程

以下命令按照上述配置进行编译，生成的可执行文件位于`build`文件夹下：
``` shell
cmake --build build
```
