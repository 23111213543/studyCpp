#include <iostream>
#include <cstdint> // ���� uintptr_t �� intptr_t �Ķ���

struct MyStruct {
    int a;
    double b;
    char c;
};

int main() {
    MyStruct myStruct;
    MyStruct* ptr = &myStruct;

    // ��ָ��ת��Ϊ�������� uintptr_t
    uintptr_t intPtr = reinterpret_cast<uintptr_t>(ptr);

    // ���ԭʼָ���ת���������ֵ
    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Pointer as integer: " << intPtr << std::endl;

    // ����ṹ���Ա��ƫ����
    uintptr_t offsetB = reinterpret_cast<uintptr_t>(&ptr->b) - intPtr;
    uintptr_t offsetC = reinterpret_cast<uintptr_t>(&ptr->c) - intPtr;

    // �����Աƫ����
    std::cout << "Offset of member 'b': " << offsetB << " bytes" << std::endl;
    std::cout << "Offset of member 'c': " << offsetC << " bytes" << std::endl;

	// ʹ�� nullptr �����Աƫ����
	int offset = (int)&((MyStruct*)nullptr)->b;
	std::cout << "Offset of member 'b': " << offset << " bytes" << std::endl;
	int offset2 = (int)&((MyStruct*)nullptr)->c;
	std::cout << "Offset of member 'c': " << offset2 << " bytes" << std::endl;

    return 0;
}
