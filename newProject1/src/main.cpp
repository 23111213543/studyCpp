#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::sort 和 std::find

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
	os << "Elements in the vector: ";
	for (int num : vec) {
		os << num << " ";
	}
	return os;

}

struct Vertex {
    float x, y, z;
    Vertex(float x = 0, float y = 0, float z = 0)
        : x(x), y(y), z(z) {
        std::cout << "Constructed Vertex!" << std::endl;
    }

    Vertex(const Vertex& other)
        : x(other.x), y(other.y), z(other.z) {
        std::cout << "Copied Vertex!" << std::endl;
    }
};
int main() {
    // 定义和初始化一个 std::vector
    std::vector<int> numbers = { 5, 3, 8, 1, 2 };

    // 添加元素
    numbers.push_back(6);
    numbers.push_back(7);

	std::cout << numbers << std::endl;

    // 插入元素
    numbers.insert(numbers.begin() + 1, 10); // 在索引1处插入10
	std::cout << numbers << std::endl;
    // 访问元素
    std::cout << "Element at index 0: " << numbers[0] << std::endl;
    std::cout << "Element at index 1: " << numbers.at(20) << std::endl;//
	//at()方法会检查索引是否越界，如果越界会抛出异常, []不会检查索引是否越界，如果越界会导致未定义行为, 所以at()更安全, at越界返回

    // 遍历元素
    std::cout << "Elements in the vector and every+1: ";
	// 使用范围 for 循环遍历元素, 从 C++11 开始支持，用于遍历容器，int num 是一个临时变量，用于存储容器中的元素，numbers 是容器，int& num好处在与不会产生临时变量，效率更高，而且可以修改容器中的元素
    for (int &num : numbers) {
        num = num + 1;
        std::cout << num << " ";
		
    }
    std::cout << std::endl;

	// 使用迭代器遍历元素，迭代器是一个指向容器中元素的指针，可以用于遍历容器中的元素
	//优点：可以遍历所有容器，不仅仅是vector，而且可以遍历map，set等，而且可以修改容器中的元素，
	//缺点：代码比较繁琐
    std::cout << "Elements in the vector (using iterator): ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 获取占用内存大小
    std::cout << "Size of the vector: " << numbers.size() << std::endl;

	// 检查是否为空，如果为空返回 true，否则返回 false
    std::cout << "Is the vector empty? " << (numbers.empty() ? "Yes" : "No") << std::endl;

	// 删除元素，erase(),括号里面是迭代器，删除迭代器指向的元素,erase()返回的是下一个元素的迭代器,删除所有元素可以使用clear()
    numbers.erase(numbers.begin() + 1); // 删除索引1处的元素

    // 排序
	std::cout << "Number by sort:" ;
    std::sort(numbers.begin(), numbers.end());
	std::cout << numbers << std::endl;
	// 查找元素,find()返回的是迭代器，如果找到返回元素的迭代器，否则返回容器的end()迭代器
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "Element 8 found at index: " << std::distance(numbers.begin(), it) << std::endl;
    }
    else {
        std::cout << "Element 8 not found" << std::endl;
    }

    // 反转
    std::reverse(numbers.begin(), numbers.end());
	std::cout << numbers << std::endl;
    // 遍历元素
    std::cout << "Elements in the vector after reverse: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 清空 vector
    numbers.clear();
    std::cout << "Size of the vector after clear: " << numbers.size() << std::endl;


	std::vector<Vertex> vertices;
    
	vertices.push_back(Vertex(1, 2, 3));
    //第一次push，	Vertex(1, 2, 3) 被创建并复制到 vertices 中。调用复制构造函数 1 次
	vertices.push_back(Vertex(4, 5, 6));
    //由于当前容量为 1，std::vector 需要扩展容量。通常情况下，std::vector 会将容量翻倍，因此它会分配一个容量为 2 的新内存块。现有的元素 Vertex(1, 2, 3) 被复制到新的内存块中。Vertex(4, 5, 6) 被创建并复制到 vertices 中。调用复制构造函数 2 次（1 次用于复制现有元素，1 次用于新元素）。
	vertices.push_back(Vertex(7, 8, 9));
    //由于当前容量为 2，std::vector 需要再次扩展容量。通常情况下，std::vector 会将容量翻倍，因此它会分配一个容量为 4 的新内存块。现有的元素 Vertex(1, 2, 3) 和 Vertex(4, 5, 6) 被复制到新的内存块中。Vertex(7, 8, 9) 被创建并复制到 vertices 中。调用复制构造函数 3 次（2 次用于复制现有元素，1 次用于新元素）
    //一共1+2+3=6
	std::cout << "Vertices:" << std::endl;
	vertices.clear();
    //优化后：
    std::vector<Vertex> vertices4;
    //
    vertices4.reserve(3); // 预先分配足够的空间，避免多次扩展
	//push_back()方法会在需要时扩展容量，这可能会导致多次内存分配和元素复制。如果你知道要添加的元素数量，可以使用 reserve() 方法预先分配足够的空间，避免多次扩展。
	//emplace_back()方法会在容器的末尾直接构造元素，而不是先创建一个临时对象，然后再复制到容器中。这样可以避免多余的复制操作，提高性能。
    vertices4.emplace_back(1, 2, 3);
    vertices4.emplace_back(4, 5, 6);
    vertices4.emplace_back(7, 8, 9);
	//调用构造函数 3 次,没有调用复制构造函数
    vertices4.clear();
	
   

	std::cout << "start reserve" << std::endl;
    // 使用 reserve 方法
    std::vector<Vertex> vertices3;
    vertices3.reserve(3); // 预先分配内存，但不初始化元素，所以容量变为 3，但是内存大小为 0,调用构造函数 0 次
    std::cout << "After reserve, size: " << vertices3.size() << ", capacity: " << vertices3.capacity() << std::endl;

    vertices3.push_back(Vertex(1, 2, 3));
    vertices3.push_back(Vertex(4, 5, 6));
    vertices3.push_back(Vertex(7, 8, 9));
    std::cout << "After push_back, size: " << vertices3.size() << ", capacity: " << vertices3.capacity() << std::endl;

    // 使用带有初始大小的构造函数
    std::vector<Vertex> vertices2(3); // 分配内存并初始化3个元素，调用默认构造函数 3 次
    std::cout << "After constructor, size: " << vertices2.size() << ", capacity: " << vertices2.capacity() << std::endl;

    vertices2[0] = Vertex(1, 2, 3);
    vertices2[1] = Vertex(4, 5, 6);
    vertices2[2] = Vertex(7, 8, 9);
    std::cout << "After assignment, size: " << vertices2.size() << ", capacity: " << vertices2.capacity() << std::endl;

  


	std::cin.get();











    return 0;
}

