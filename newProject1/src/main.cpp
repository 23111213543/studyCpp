#include <iostream>
#include <string>
#include <vector>
#include<typeinfo>
#include <algorithm> 


std::string GetName() {
	return "Cherno";
}
//明确指定返回类型，return "Cherno"; 返回一个字符串字面量。由于字符串字面量是 const char* 类型，编译器会自动将其转换为 std::string 类型。
auto GetName2() -> std::string {
	return "Cherno";
}

auto GetName3()  {
	return "Cherno";
}

int main() {
    auto a = 5;
	auto b = a;
	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;

	auto c = 5l;
	std::cout << "c size:" << sizeof(c) << std::endl; //c size : 4
		
	std::cout << "Type of c: " << typeid(c).name() << std::endl;//Type of c: long

	auto d = 5.0f;
	std::cout << "d size:" << sizeof(d) << std::endl; //d size : 4
	std::cout << "Type of d: " << typeid(d).name() << std::endl;//Type of d: float

	auto e = 5.0;
	std::cout << "e size:" << sizeof(e) << std::endl; //e size : 8
	std::cout << "Type of e: " << typeid(e).name() << std::endl;//Type of e: double

	auto f = 5.0L;
	std::cout << "f size:" << sizeof(f) << std::endl; //f size : 8 
	std::cout << "Type of f: " << typeid(f).name() << std::endl;//Type of f: long double

	auto g = "Cherno";
	std::cout << "g size:" << sizeof(g) << std::endl; //g size : 8
	std::cout << "Type of g: " << typeid(g).name() << std::endl;//Type of g:  char const * __ptr64  8*8=64

	auto h = GetName();

	int i = h.size();
	std::cout << "string length:" << i << std::endl; //"Cherno" 6 char ,so length is 6

	auto j = GetName3(); //j is const char*
	//int k = j.size();   //error: request for member 'size' in 'j', which is of non-class type 'const char*'
	//std::cout << "string length:" << k << std::endl; //"Cherno" 6 char ,so length is 6
	
	//auto的优点在于自动推导类型，但是在某些情况下，auto并不是一个好的选择，比如在函数参数中，auto无法推导出类型，所以在函数参数中，我们应该使用明确的类型。
	//而且通常我们不知道auto推导出来的类型什么时候改变，所以在代码中应该尽量避免使用auto，除非必要的情况下。

	for(auto& k : h)
	{
		std::cout << k << std::endl;	
	}
	//output:c h e r n o
	
};
    
    

