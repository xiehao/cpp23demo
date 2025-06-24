// main.cpp
import std; // 导入标准库模块 (需要 GCC 15+ 和 -fmodules-ts)

int main() {
    std::println("Hello from C++ Modules with import std;!");
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto sum = 0;
    for (auto &&num : numbers) {
        sum += num;
    }
    
    std::println("Vector elements: {}", numbers); // C++23 std::println (也包含在 std 模块中)
    std::println("Sum: {}", sum);

    return 0;
}