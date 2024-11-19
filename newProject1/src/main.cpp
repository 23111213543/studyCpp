#include<iostream>

#define LOG(x) std::cout << x << std::endl

//����һ��interface��ʵ������class�����interface��һ������GetClassName()������һ���ַ�����
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
	Player(const std::string& name) //���ǹ��캯�������ƣ���������ͬ��
		: m_Name(name) {
	}								//const std::string& name�����ǹ��캯���Ĳ�������ʾһ�������ַ������á�
									//: ,��ʼ���б�Ŀ�ʼ��
									//	m_Name(name)��ʹ�ô���Ĳ���name��ʼ����Ա����m_Name��
									//	{ }�����캯�������壬��ǰΪ�ա�
	std::string GetName() override{ return m_Name; } 

	//C++11������override�ؼ��֣������߱�����������ͼ��дһ�����������������ͼ��дһ�������ڵĺ��������ߺ���ǩ����ƥ�䣬����������������
	//�������Ǳ������
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
	
	Entity* e=new Entity; //����һ��Entity���󣬲������ַ����ָ��e��
	std::cout << e->GetName() << std::endl; //->��������ڷ���ָ��ָ��Ķ���ĳ�Ա��
	PriintName(e);
	Print(e);

	Player* p = new Player("Cherno"); //����һ��Player���󣬲������ַ����ָ��p��
	std::cout << p->GetName() << std::endl; //->��������ڷ���ָ��ָ��Ķ���ĳ�Ա��
	PriintName(p);
	Print(p);	


	Entity* entity = p; //��Player����ĵ�ַ����Entityָ�롣
	std::cout << entity->GetName() << std::endl; //->��������ڷ���ָ��ָ��Ķ���ĳ�Ա��
	PriintName(entity);
	Print(entity);
	
	
	
	//�����entity��һ��Entityָ�룬������ָ�����һ��Player������ˣ�����entity->GetName()������Player::GetName()�����GetName()�����麯����ûдvirtual����ô������Entity::GetName()������д��virtual��ӡ�������������GetName()��ûдvirtual��ӡ�������Ǹ����GetName()��
	//������ΪGetName()��һ���麯��������Entity���б�����Ϊ�麯���������Player���б���д��
	//����Ƕ�̬�ĸ����������ʱѡ����õĺ�����
	//



}