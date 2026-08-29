# C++23实例：import std;

## 配置工程

以下命令在项目根目录新建`build`文件夹，并将编译产生的所有文件置于此处；采用Ninja作为组织工具（其他工具暂不支持）；尽量采用最新的GCC（下述`g++`至少应保证16.1以上版本）作为编译器：

```shell
cmake -S . -B build -G Ninja -D CMAKE_CXX_COMPILER=g++
```

## 编译工程

以下命令按照上述配置进行编译，生成的可执行文件位于`build`文件夹下：

```shell
cmake --build build
```

## 运行工程

输入以下命令运行可执行文件（在`CMakeLists.txt`中已将目标命名为`my_app`)：

```Shell
build/my_app
```

如无意外，应有如下输出：

```Shell
Hello from C++ Modules with import std;!
Vector elements: [1, 2, 3, 4, 5]
Sum: 15
```
