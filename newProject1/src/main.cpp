#include <iostream>
#include <string>
#include<array>
#include <vector>
#include<typeinfo>
#include <algorithm> 
#include <ctime>

//��̬��������̬�����ڳ�����������������ڶ����ڣ������ǵ�����������ڶ������ǵ��ļ�
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
	 std::cout << "Hello, World!3 Value a��" <<a<< std::endl;

 }

 void ForeEach(const std::vector<int> &values,void(*function)(int))
 {
	 for (int value : values)
		 function(value);
 }
int main()
{
	//������ָ�븳ֵ��һ��������Ȼ��������������ԭ���Ǽ����������ʱ�򽫺�������һ���ڴ���
	//Ȼ�����������һ����ַ�������ַ���Ǻ���ָ�룬ÿ�ε������������ʱ�򣬾��ǵ����������ָ��
	//����ָ��������Ƿ���ֵ����+������+��������
	//����ָ���������ʽ�Ƿ���ֵ����+(*������)+�������ͣ�
	auto function = HelloWorld;
	//function��������void(*function)()��Ҳ���Ƿ���ֵ��void����������function�������ǿ�
	function();
	
	function();

	//��ʹ��auto�ķ�ʽ
	void(*Cherno)();

	Cherno = HelloWorld2;

	Cherno();

	HelloWorld2();

	

	HelloWorld3(8);

	//ʵ�ú���ָ�������
    std::vector<int> values = { 1,2,3,4,5 };
    ForeEach(values, [](int value) { std::cout << value << std::endl; });

	std::for_each(values.begin(), values.end(), [](int value) { std::cout << value << std::endl; });




	std::cin.get();	

};


    

