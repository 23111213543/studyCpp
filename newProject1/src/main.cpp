#include <iostream>
#include <string>
class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
		
	}
	//这个友元函数是一个重载的<<运算符，用于将String对象输出到标准输出流（如std::cout）。
	// 具体来说，这段代码声明了一个友元函数，使得std::ostream& operator<<(std::ostream& stream, const String& string)可以访问String类的私有成员m_Buffer。
	// 这样，当你使用std::cout << stringObject; 时，程序会调用这个友元函数，将String对象的内容输出到控制台
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	
	//重载[]运算符
	//重载[]运算符的目的是让String类的对象可以像数组一样使用下标运算符[]。
	// 例如，如果你有一个String对象string，你可以使用string[0]来访问字符串的第一个字符。
	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}
	// Destructor
	~String()
	{
		delete[] m_Buffer;
	}

	// Copy Constructor
	//拷贝构造函数是一种特殊的构造函数，它在创建对象时，使用同一类的另一个对象来初始化新对象。

	//拷贝构造函数通常用于：
		//1. 通过使用另一个同类型的对象来初始化新创建的对象。
		//2. 复制对象把它作为参数传递给函数。
		//3. 复制对象，并从函数返回这个对象。
	//拷贝构造函数的声明和定义如下：
	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;	
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		m_Buffer[m_Size] = 0;
	}
	//String(const String& other)=delete; //禁用拷贝构造函数,这样就不能直接复制string到second
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}
//函数传参如果不加&，会复制一次，外部的second复制给内部参数string，增加时间调用深拷贝
void PrintString(const String& string)
{
	std::cout << string << std::endl;
}
int main() {
	String string = "Cherno";
	//直接复制string到second，这个错误发生的原因是 String 类没有实现正确的拷贝构造函数，导致 m_Buffer 指针被浅拷贝。当析构函数被调用时，会尝试删除同一块内存两次，从而导致双重删除错误。
	//这可能是因为：
		//1.	默认的拷贝构造函数被使用，它对 m_Buffer 指针进行了浅拷贝。
		//2.	当 second 作为 string 的副本创建时，这两个对象共享同一个 m_Buffer 指针。
		//3.	当 string 和 second 的析构函数被调用时，它们都尝试删除同一块内存，导致双重删除。
	//解决这个问题的方法是实现一个正确的拷贝构造函数，它会为 second 分配一个新的内存块，并将 string 的内容复制到这个新的内存块中。
	//这样，当 string 和 second 被销毁时，它们会分别删除各自的内存块，而不会导致双重删除错误。
	String second = string;

	//second[2]= 'a'; 等号右边是一个char类型，左边是char*类型，
	second[2] = 'a';
	//这个没有调用拷贝构造函数，因为这个是直接赋值，不是初始化

	PrintString(string);
	PrintString(second);
	
	std::cin.get();
	
}