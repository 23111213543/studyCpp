#include<iostream>

void increment1(int* value)
{
	(*value)++;
}
//�������������ã�����ָ�룬�൱�ڴ���a,Ȼ��a�ı���Ϊvalue��value++����a++	
void increment2(int& value)
{
	value++;
}
int main()
{
	int a = 5;
	int* b = &a;
	// ���õı�������"����"�����õı�����ָ�룬���õı�����ָ�볣��
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