#include <iostream>
#include <string>
#include<array>
#include <vector>
#include<typeinfo>
#include <algorithm> 
#include <ctime>



int main() {
	// lambda表达式
    //[capture](parameters) -> return_type { body }
    //•	capture：捕获列表，用于捕获外部变量。
    //    •	parameters：参数列表，类似于普通函数的参数列表。
    //    •	return_type：返回类型，可以省略，编译器会自动推断。
    //    •	body：函数体，包含要执行的代码

	auto greet = []() { std::cout << "Hello, World!" << std::endl; };//greet类型为lambda表达式，定义一个lambda表达式，并将其赋值给一个变量greet。
    greet();  // 调用lambda表达式

	// 捕获外部变量
    int x = 10;
    auto printX = [x]() { std::cout << "x = " << x << std::endl; };
    printX();  // 输出：x = 10

	// 修改外部变量
	auto incrementX = [&x]() { x++; };

	// 输出x的值
	std::cout << "x = " << x << std::endl;  // 输出：x = 10

    //在STL算法中使用lambda表达式
    std::vector<int> values = { 1, 2, 3, 4, 5 };
    std::for_each(values.begin(), values.end(), [](int value) { std::cout << value << " "; });
    std::cout << std::endl;  // 输出：1 2 3 4 5

    


    //按值捕获多个外部变量
    int factor = 2;
    int offset = 3;
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    // 按值捕获factor和offset
	//lanbda表达式中���参数列表中的参数名不一定要和外部变量名一样,只要类型匹配即可,例如这里的value,这个lambda是一个匿名函数,它的参数是value,对value进行乘权重，加偏移量的操作
    std::for_each(values.begin(), values.end(), [factor, offset](int value) {
        std::cout << (value * factor + offset) << " ";
        });
    std::cout << std::endl;  // 输出：5 7 9 11 13



    std::vector<int> values2 = { 1, 2, 3, 4, 5 };
    // 使用std::find_if查找第一个大于3的元素
    auto it = std::find_if(values2.begin(), values2.end(), [](int value) { return value > 3;});

    if (it != values.end()) {
        std::cout << "第一个大于3的元素是: " << *it << std::endl;
    }
    else {
        std::cout << "没有找到大于3的元素" << std::endl;
    }

    return 0;
}


    

