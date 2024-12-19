#include <iostream>
#include <cstdint> // 包含 uintptr_t 和 intptr_t 的定义

struct MyStruct {
    int a;
    double b;
    char c;
};

int main() {
    MyStruct myStruct;
    MyStruct* ptr = &myStruct;

    // 将指针转换为整数类型 uintptr_t
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);

    // 输出原始指针和转换后的整数值
    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Pointer as integer: " << intPtr << std::endl;

    // 计算结构体成员的偏移量
    uintptr_t offsetB = reinterpret_cast<uintptr_t>(&ptr->b) - intPtr;
    uintptr_t offsetC = reinterpret_cast<uintptr_t>(&ptr->c) - intPtr;

    // 输出成员偏移量
    std::cout << "Offset of member 'b': " << offsetB << " bytes" << std::endl;
    std::cout << "Offset of member 'c': " << offsetC << " bytes" << std::endl;

	// 使用 nullptr 计算成员偏移量
	int offset = (int)&((MyStruct*)nullptr)->b;
	std::cout << "Offset of member 'b': " << offset << " bytes" << std::endl;
	int offset2 = (int)&((MyStruct*)nullptr)->c;
	std::cout << "Offset of member 'c': " << offset2 << " bytes" << std::endl;

    return 0;
}
