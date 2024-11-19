#include<iostream>

#define LOG(x) std::cout << x << std::endl

//定义一个interface，实际上是class，这个interface有一个函数GetClassName()，返回一个字符串。
class Printable
{
public:
	virtual std::string GetClassName() = 0;

};
class Entity : public Printable
{
public:
	virtual std::string GetName() { return "Entity"; }	
	std::string GetClassName() override { return "Entity"; }


};

class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name) //这是构造函数的名称，与类名相同。
		: m_Name(name) {
	}								//const std::string& name：这是构造函数的参数，表示一个常量字符串引用。
									//: ,初始化列表的开始。
									//	m_Name(name)：使用传入的参数name初始化成员变量m_Name。
									//	{ }：构造函数的主体，当前为空。
	std::string GetName() override{ return m_Name; } 

	//C++11引入了override关键字，它告诉编译器我们试图重写一个函数。如果我们试图重写一个不存在的函数，或者函数签名不匹配，编译器将发出错误。
	//帮助我们避免错误。
	std::string GetClassName() override { return "Player"; }

	
};
void PriintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}


void Print(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}

int main()
{	
	
	Entity* e=new Entity; //创建一个Entity对象，并将其地址赋给指针e。
	std::cout << e->GetName() << std::endl; //->运算符用于访问指针指向的对象的成员。
	PriintName(e);
	Print(e);

	Player* p = new Player("Cherno"); //创建一个Player对象，并将其地址赋给指针p。
	std::cout << p->GetName() << std::endl; //->运算符用于访问指针指向的对象的成员。
	PriintName(p);
	Print(p);	


	Entity* entity = p; //将Player对象的地址赋给Entity指针。
	std::cout << entity->GetName() << std::endl; //->运算符用于访问指针指向的对象的成员。
	PriintName(entity);
	Print(entity);
	
	
	
	//在这里，entity是一个Entity指针，但是它指向的是一个Player对象。因此，调用entity->GetName()将调用Player::GetName()。如果GetName()不是虚函数，没写virtual，那么将调用Entity::GetName()。父类写了virtual打印出来就是子类的GetName()。没写virtual打印出来就是父类的GetName()。
	//这是因为GetName()是一个虚函数，它在Entity类中被声明为虚函数，因此在Player类中被重写。
	//这就是多态的概念，即在运行时选择调用的函数。
	//



}