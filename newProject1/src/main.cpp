#include <iostream>
#include <string>
#include<array>
#include <vector>
#include<typeinfo>
#include <algorithm> 
#include <ctime>

//静态函数：静态函数在程序的整个生命周期内都存在，但它们的作用域仅限于定义它们的文件
 void HelloWorld()
{
	std::cout << "Hello, World!" << std::endl;
}

 void HelloWorld2()
 {
	 std::cout << "Hello, World!2" << std::endl;
 }

 void HelloWorld3(int a)
 {
	 std::cout << "Hello, World!3 Value a：" <<a<< std::endl;

 }

 void ForeEach(const std::vector<int> &values,void(*function)(int))
 {
	 for (int value : values)
		 function(value);
 }
int main()
{
	//将函数指针赋值给一个变量，然后调用这个变量。原理是计算器编译的时候将函数存在一段内存中
	//然后这个函数有一个地址，这个地址就是函数指针，每次调用这个函数的时候，就是调用这个函数指针
	//函数指针的类型是返回值类型+变量名+参数类型
	//函数指针的声明方式是返回值类型+(*变量名)+参数类型，
	auto function = HelloWorld;
	//function的类型是void(*function)()，也就是返回值是void，变量名是function，参数是空
	function();
	
	function();

	//不使用auto的方式
	void(*Cherno)();

	Cherno = HelloWorld2;

	Cherno();

	HelloWorld2();

	

	HelloWorld3(8);

	//实用函数指针的例子
    std::vector<int> values = { 1,2,3,4,5 };
    ForeEach(values, [](int value) { std::cout << value << std::endl; });

	std::for_each(values.begin(), values.end(), [](int value) { std::cout << value << std::endl; });




	std::cin.get();	

};


    

