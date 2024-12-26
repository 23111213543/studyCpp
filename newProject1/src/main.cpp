#include <iostream>
#include <string>
#include<array>
#include <vector>
#include<typeinfo>
#include <algorithm> 
#include <ctime>


void PrintArray(const std::array<int, 5>& arr) {
	for (const auto& elem : arr) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

int main() 
{
	

	std::array<int, 5> arr = { 1, 2, 3, 4, 5 };
	PrintArray(arr);
	//arr[6] = 6;	
	
	//ȱ�㣺���Ե�ʱ�����ʾ���󣬵��ǲ��ᱨ������������������exe
	//����������������Խ�磬���ǵ�������������Խ��
	
	std::cout << arr.size() << std::endl;

	//�ŵ�array.size���ԣ�����a.size������
	//1.	���Ͱ�ȫ��std::array��һ��ģ���࣬�ṩ�����Ͱ�ȫ�Ľӿڡ�
	//2.	�̶���С��std::array�Ĵ�С�ڱ���ʱȷ�������ܶ�̬�ı䣬����Ҳ��ζ�����Ĵ�С�ǹ̶��ġ�
	//3.	��׼��֧�֣�std::array��C++��׼���һ���֣��ṩ��������õĳ�Ա��������size()��at()��fill()�ȡ�
	//4.	��STL���ݣ�std::array�������׼ģ��⣨STL�����㷨�������ܺõ����ʹ�á�
	//5.	�߽��飺std::array��at()�����ṩ�˱߽��飬��ֹԽ����ʡ�
	//6.	���ܣ�std::array��������C��������൱����Ϊ����һ���̶���С�����飬����Ҫ��̬�����ڴ档
	int a[5] = { 1,2,3,4,5 };
	std::cout << "Array: ";
	for (int i = 0; i < 5; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	//a[6] = 6;
	//�����Ա��룬�ᱨ��

	#include <iostream>
	#include <array>

	
	
	std::array<int, 5> arr2 = { 1, 2, 3, 4, 5 };
	PrintArray(arr);

	// ����ʾ���������˴������͵�����
	 std::array<double, 5> wrongArr = {1.1, 2.2, 3.3, 4.4, 5.5};
	 PrintArray(reinterpret_cast<std::array<int, 5>&>(wrongArr));  // ���������ᵼ�±������

	return 0;





	return 0;
    
	
};
    
    

