#include <iostream>
#include <string>
#include <vector>
#include<typeinfo>
#include <algorithm> 


std::string GetName() {
	return "Cherno";
}
//��ȷָ���������ͣ�return "Cherno"; ����һ���ַ����������������ַ����������� const char* ���ͣ����������Զ�����ת��Ϊ std::string ���͡�
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
	
	//auto���ŵ������Զ��Ƶ����ͣ�������ĳЩ����£�auto������һ���õ�ѡ�񣬱����ں��������У�auto�޷��Ƶ������ͣ������ں��������У�����Ӧ��ʹ����ȷ�����͡�
	//����ͨ�����ǲ�֪��auto�Ƶ�����������ʲôʱ��ı䣬�����ڴ�����Ӧ�þ�������ʹ��auto�����Ǳ�Ҫ������¡�

	for(auto& k : h)
	{
		std::cout << k << std::endl;	
	}
	//output:c h e r n o
	
};
    
    

