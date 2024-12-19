#include <iostream>

class Base {
public:
    Base(int value) {
        std::cout << "Base initialized with value: " << value << std::endl;
    }
};

class MyClass : public Base {
private:
    const int m_ConstValue;
    int m_X;
    int m_Y;
public:
    // 使用初始化列表
	// 初始化列表的语法：在构造函数的参数列表后面使用冒号（:）进行初始化列表，然后在初始化列表中以逗号分隔的形式初始化成员变量
	// 初始化列表的优点：初始化列表可以保证成员变量的初始化顺序，避免了成员变量初始化顺序不确定的问题
	//初始化列表的语法：在构造函数的参数列表后面使用冒号（:）进行初始化列表，然后在初始化列表中以逗号分隔的形式初始化成员变量
	//初始化列表的效率：初始化列表的效率要高于在构造函数体内进行赋值操作，因为初始化列表是直接初始化成员变量，而不是先默认构造再赋值
	//常量和引用成员：常量成员和引用成员只能在初始化列表中进行初始化，不能在构造函数体内进行赋值操作
	//基类初始化：派生类的构造函数不能在构造函数体内调用基类的构造函数，必须使用初始化列表
    MyClass(int x, int y, int constValue)
		: Base(x + y), m_ConstValue(constValue), m_X(x), m_Y(y) {
        std::cout << "MyClass initialized using initialization list" << std::endl;
        std::cout << "m_ConstValue:"<<m_ConstValue << std::endl;
		std::cout << "m_X:" << m_X << std::endl;
		std::cout << "m_Y:" << m_Y << std::endl;
    }

    // 在构造函数体内使用 this-> 进行初始化
	// 注意：这种方式不是最佳实践，因为在构造函数体内使用 this-> 进行初始化会导致成员变量的初始化顺序不确定
	// 例如：m_ConstValue 会在 m_X 和 m_Y 之前初始化
	// 但是在初始化列表中，成员变量的初始化顺序是确定的
	// 所以，最佳实践是使用初始化列表进行初始化
    //效率较低：在构造函数体内进行赋值操作，成员变量会先被默认构造，然后再赋值，可能会导致不必要的性能开销。
    //常量成员和引用成员：常量成员和引用成员不能在构造函数体内进行赋值初始化，必须使用初始化列表。
    //基类初始化：派生类的构造函数不能在构造函数体内调用基类的构造函数，必须使用初始化列表。
    MyClass(int x, int y) : Base(x + y), m_ConstValue(0) {
        this->m_X = x;
        this->m_Y = y;
        std::cout << "MyClass initialized using this-> in constructor body" << std::endl;
		std::cout << "m_ConstValue:" << m_ConstValue << std::endl;
		std::cout << "m_X:" << m_X << std::endl;
		std::cout << "m_Y:" << m_Y << std::endl;
    }
};

int main() {
    MyClass obj1(1, 2, 3); // 使用初始化列表
    MyClass obj2(4, 5);    // 在构造函数体内使用 this-> 进行初始化

    return 0;
}
