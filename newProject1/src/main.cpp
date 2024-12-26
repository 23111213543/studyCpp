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
	
	//缺点：调试的时候会显示错误，但是不会报错，可以正常运行生成exe
	//编译器不会检查数组越界，但是调试器会检查数组越界
	
	std::cout << arr.size() << std::endl;

	//优点array.size可以，但是a.size不可以
	//1.	类型安全：std::array是一个模板类，提供了类型安全的接口。
	//2.	固定大小：std::array的大小在编译时确定，不能动态改变，但这也意味着它的大小是固定的。
	//3.	标准库支持：std::array是C++标准库的一部分，提供了许多有用的成员函数，如size()、at()、fill()等。
	//4.	与STL兼容：std::array可以与标准模板库（STL）的算法和容器很好地配合使用。
	//5.	边界检查：std::array的at()方法提供了边界检查，防止越界访问。
	//6.	性能：std::array的性能与C风格数组相当，因为它是一个固定大小的数组，不需要动态分配内存。
	int a[5] = { 1,2,3,4,5 };
	std::cout << "Array: ";
	for (int i = 0; i < 5; i++) {
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;

	//a[6] = 6;
	//不可以编译，会报错

	#include <iostream>
	#include <array>

	
	
	std::array<int, 5> arr2 = { 1, 2, 3, 4, 5 };
	PrintArray(arr);

	// 错误示例：传递了错误类型的数组
	 std::array<double, 5> wrongArr = {1.1, 2.2, 3.3, 4.4, 5.5};
	 PrintArray(reinterpret_cast<std::array<int, 5>&>(wrongArr));  // 这种做法会导致编译错误

	return 0;





	return 0;
    
	
};
    
    

