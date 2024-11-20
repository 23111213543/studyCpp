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

    // 连接字符串
    str1 += " ";
    str1 += str2;
    std::cout << "Concatenated string: " << str1 << std::endl;

    std::string str3 = "Hello";// + "World"; // 编译错误 因为字符串字面值是常量指针，不能直接相加，不能指针加指针
    str3 = str3 + " World";
    std::cout << "Concatenated string: " << str3 << std::endl;


    // 查找子字符串
	size_t pos = str1.find("World"); // size_t 是一种数据类型，通常被用于存储数组的长度 ,pos是一个变量，用于存储子字符串的位置
        if (pos != std::string::npos) // std::string::npos 表示未找到子字符串,npos是一个常量，是一个无符号整数，它的值通常是-1，(FFFFFFFF)表示没有找到子字符串
            {
                std::cout << "Npos is " << unsigned int(std::string::npos) << std::endl;
                std::cout << "'World' found at position: " << pos << std::endl;
            }
	    else
	        {
		        std::cout << "'World' not found" << std::endl;
	        }
	
	// 从指定位置开始查找子字符串
		pos = str1.find("World", 10); //没找到，返回npos，pos=4294967295（FFFFFFFF）无符号整数的最大值
	    if (pos != std::string::npos) // std::string::npos 表示未找到子字符串,npos是一个常量，是一个无符号整数，它的值通常是-1，表示没有找到子字符串
            {
                std::cout << "'World' found at position: " << pos << std::endl;
            }
        else 
		    {
			    std::cout << "'World' not found" << std::endl;
		    }
    // 获取子字符串
		std::string substr = str1.substr(6, 5); // 从第6个字符开始，获取5个字符
    std::cout << "Substring: " << substr << std::endl;

    // 修改字符串
	str1.replace(6, 5, "C++");// 从第6个字符开始，替换5个字符
    std::cout << "Modified string: " << str1 << std::endl;

    // 清空字符串
	str1.clear();// 清空字符串
	std::cout << "Cleared string: " << str1 << std::endl;
	const char name_cherno[8] = "Che\0rno";
	
	std::cout << strlen(name_cherno) << std::endl; // 3,因为\0后面的字符不会被输出

	const int MAX_AGE = 90;
	int* a = new int;

	*a = 2;
	a = (int*)&MAX_AGE;
	
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl; // 90

	*a = 22;	
	std::cout << *a << std::endl;
	std::cout << MAX_AGE << std::endl; // 90，因为MAX_AGE是一个常量，不能被修改
   
	const int* a1 = new int;  //const int* a1 表示 a1 是一个指向 const int 的指针，因此不能通过 a1 修改它所指向的值。
	//*a = 2;
	a1 = (int*)&MAX_AGE;
	//*a1 = 22;
	std::cout << *a1 << std::endl;
	std::cout << MAX_AGE << std::endl; // 22，因为MAX_AGE是一个常量，不能被修改

	int* const a2 = new int; //int* const a2 表示 a2 是一个指向 int 的常量指针，因此不能通过 a2 修改它所指向的地址。
	*a2 = 2;
	//a2 = (int*)&MAX_AGE; // 编译错误，因为a2是一个常量指针，不能被修改
	*a2 = 22;
	std::cout << *a2 << std::endl;
	std::cout << MAX_AGE << std::endl; // 22，因为MAX_AGE是一个常量，不能被修改
	
	const int* const a3 = new const int(1);//const int* const a3 表示 a3 是一个指向 const int 的常量指针，因此不能通过 a3 修改它所指向的值，也不能通过 a3 修改它所指向的地址。
	
	std::cout << *a3 << std::endl;
	std::cin.get();

}