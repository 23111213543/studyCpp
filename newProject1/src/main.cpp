#include<iostream>

int main()
{	//练习指针	
	int var = 8;
	int* ptr = nullptr;  
	//nullptr	是什么意思？  nullptr是一个空指针常量，可以赋值给任何指针类型，表示指针不指向任何对象。指针地址初始化为	0x0000000000000000
	ptr = &var;
	//新的指针指向原指针的地址，存着ptr的地址
	int** ptr2 = &ptr;
	// 逆向指针改指向的数据
	*ptr = 10;
	//初始化指针指向的数据为100
	int* ptr3 = new int(10);
	// 指针指向的数据内容为 a ,ASCII码61
	char* ptr4 = new char('a');	
	// 初始化指针的位数为10byte，但是没有初始化数据，数据随机
	char* ptr5 = new char[10];
	// 初始化指针的位数为10byte，初始化数据为0
	char* ptr6 = new char[10]();
	
	std::cout << var<< std::endl;
	std::cin.get();	
	
	return 0;


}