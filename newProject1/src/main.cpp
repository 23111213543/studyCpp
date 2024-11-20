#include<iostream>
#include<string>
#define LOG(x) std::cout << x << std::endl

class Entity
{
private:
	int m_X, m_Y;
public:
}

int main()
{	
	const	char* name = "Cherno";
	LOG(name);
	

	std::string name2 = "Cherno";
	std::cout << &name2 << std::endl;
	std::cout << "Address: " << static_cast<const void*>(name2.c_str()) << std::endl;
	std::cout << "Length: " << name2.length() << std::endl;
	std::cout << "Capacity: " << name2.capacity() << std::endl;


	const	char name3[7] = {'C','h','e','r','n','o','\0'};
	LOG(name3);

    std::string str1 = "Hello";
    std::string str2 = "World";

    // �����ַ���
    str1 += " ";
    str1 += str2;
    std::cout << "Concatenated string: " << str1 << std::endl;

    std::string str3 = "Hello";// + "World"; // ������� ��Ϊ�ַ�������ֵ�ǳ���ָ�룬����ֱ����ӣ�����ָ���ָ��
    str3 = str3 + " World";
    std::cout << "Concatenated string: " << str3 << std::endl;


    // �������ַ���
	size_t pos = str1.find("World"); // size_t ��һ���������ͣ�ͨ�������ڴ洢����ĳ��� ,pos��һ�����������ڴ洢���ַ�����λ��
        if (pos != std::string::npos) // std::string::npos ��ʾδ�ҵ����ַ���,npos��һ����������һ���޷�������������ֵͨ����-1��(FFFFFFFF)��ʾû���ҵ����ַ���
            {
                std::cout << "Npos is " << unsigned int(std::string::npos) << std::endl;
                std::cout << "'World' found at position: " << pos << std::endl;
            }
	    else
	        {
		        std::cout << "'World' not found" << std::endl;
	        }
	
	// ��ָ��λ�ÿ�ʼ�������ַ���
		pos = str1.find("World", 10); //û�ҵ�������npos��pos=4294967295��FFFFFFFF���޷������������ֵ
	    if (pos != std::string::npos) // std::string::npos ��ʾδ�ҵ����ַ���,npos��һ����������һ���޷�������������ֵͨ����-1����ʾû���ҵ����ַ���
            {
                std::cout << "'World' found at position: " << pos << std::endl;
            }
        else 
		    {
			    std::cout << "'World' not found" << std::endl;
		    }
    // ��ȡ���ַ���
		std::string substr = str1.substr(6, 5); // �ӵ�6���ַ���ʼ����ȡ5���ַ�
    std::cout << "Substring: " << substr << std::endl;

    // �޸��ַ���
	str1.replace(6, 5, "C++");// �ӵ�6���ַ���ʼ���滻5���ַ�
    std::cout << "Modified string: " << str1 << std::endl;

    // ����ַ���
	str1.clear();// ����ַ���
	std::cout << "Cleared string: " << str1 << std::endl;
	const char name_cherno[8] = "Che\0rno";
	
	std::cout << strlen(name_cherno) << std::endl; // 3,��Ϊ\0������ַ����ᱻ���

	const int MAX_AGE = 90;
	int* a = new int;

	*a = 2;
	a = (int*)&MAX_AGE;
	
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl; // 90

	*a = 22;	
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl; // 90����ΪMAX_AGE��һ�����������ܱ��޸�
   
	const int* a1 = new int;  //const int* a1 ��ʾ a1 ��һ��ָ�� const int ��ָ�룬��˲���ͨ�� a1 �޸�����ָ���ֵ��
	//*a = 2;
	a1 = (int*)&MAX_AGE;
	//*a1 = 22;
	std::cout << *a1 << std::endl;
	std::cout << MAX_AGE << std::endl; // 22����ΪMAX_AGE��һ�����������ܱ��޸�

	int* const a2 = new int; //int* const a2 ��ʾ a2 ��һ��ָ�� int �ĳ���ָ�룬��˲���ͨ�� a2 �޸�����ָ��ĵ�ַ��
	*a2 = 2;
	//a2 = (int*)&MAX_AGE; // ���������Ϊa2��һ������ָ�룬���ܱ��޸�
	*a2 = 22;
	std::cout << *a2 << std::endl;
	std::cout << MAX_AGE << std::endl; // 22����ΪMAX_AGE��һ�����������ܱ��޸�
	
	const int* const a3 = new const int(1);//const int* const a3 ��ʾ a3 ��һ��ָ�� const int �ĳ���ָ�룬��˲���ͨ�� a3 �޸�����ָ���ֵ��Ҳ����ͨ�� a3 �޸�����ָ��ĵ�ַ��
	
	std::cout << *a3 << std::endl;
	std::cin.get();

}