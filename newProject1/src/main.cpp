#include<iostream>

void increment1(int* value)
{
	(*value)++;
}
//传过来的是引用，不是指针，相当于传来a,然后a的别名为value，value++就是a++	
void increment2(int& value)
{
	value++;
}
int main()
{
	int a = 5;
	int* b = &a;
	// 引用的本质是起"别名"，引用的本质是指针，引用的本质是指针常量
	int& ref = a;
	increment1(&a);
	
	std::cout << a<< std::endl;
	// print a=5+1
	ref = 10;
	increment2(a);
	std::cout << a << std::endl;
	// print a=10+1
	
	std::cout << a;
	std::cin.get();	

	return 0;


}