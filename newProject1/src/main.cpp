#include<iostream>

#define LOG(x) std::cout << x << std::endl

class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	};


};

class Player : public Entity
{

public:
	const char* Name;

	void PrintName(const char* name)
	{
		Name = name;
		LOG(Name);
	}
};

int main()
{	

	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl;
	#include <iostream>

	std::cout << "Size of int: " << sizeof(int) << " bytes" << std::endl;
	std::cout << "Size of long int: " << sizeof(long int) << " bytes" << std::endl;
	std::cout << "Size of short int: " << sizeof(short int) << " bytes" << std::endl;
	std::cout << "Size of short: " << sizeof(short) << " bytes" << std::endl;
	std::cout << "Size of long: " << sizeof(long) << " bytes" << std::endl;
	std::cout << "Size of long long int: " << sizeof(long long int) << " bytes" << std::endl;
	std::cout << "Size of long long: " << sizeof(long long) << " bytes" << std::endl;
	std::cout << "Size of char: " << sizeof(char) << " bytes" << std::endl;
	std::cout << "Size of double: " << sizeof(double) << " bytes" << std::endl;
	std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
	std::cout << "Size of float: " << sizeof(float) << " bytes" << std::endl;
	



	Player player;
	player.Move(5, 5);
	player.X = 2;

	std::cin.get();


}