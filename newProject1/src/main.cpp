#include<iostream>

int main()
{	//��ϰָ��	
	int var = 8;
	int* ptr = nullptr;  
	//nullptr	��ʲô��˼��  nullptr��һ����ָ�볣�������Ը�ֵ���κ�ָ�����ͣ���ʾָ�벻ָ���κζ���ָ���ַ��ʼ��Ϊ	0x0000000000000000
	ptr = &var;
	//�µ�ָ��ָ��ԭָ��ĵ�ַ������ptr�ĵ�ַ
	int** ptr2 = &ptr;
	// ����ָ���ָ�������
	*ptr = 10;
	//��ʼ��ָ��ָ�������Ϊ100
	int* ptr3 = new int(10);
	// ָ��ָ�����������Ϊ a ,ASCII��61
	char* ptr4 = new char('a');	
	// ��ʼ��ָ���λ��Ϊ10byte������û�г�ʼ�����ݣ��������
	char* ptr5 = new char[10];
	// ��ʼ��ָ���λ��Ϊ10byte����ʼ������Ϊ0
	char* ptr6 = new char[10]();
	
	std::cout << var<< std::endl;
	std::cin.get();	
	
	return 0;


}