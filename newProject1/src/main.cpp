#include <iostream>
#include <vector>
#include <algorithm> // ���� std::sort �� std::find

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
    // ����ͳ�ʼ��һ�� std::vector
    std::vector<int> numbers = { 5, 3, 8, 1, 2 };

    // ���Ԫ��
    numbers.push_back(6);
    numbers.push_back(7);

	std::cout << numbers << std::endl;

    // ����Ԫ��
    numbers.insert(numbers.begin() + 1, 10); // ������1������10
	std::cout << numbers << std::endl;
    // ����Ԫ��
    std::cout << "Element at index 0: " << numbers[0] << std::endl;
    std::cout << "Element at index 1: " << numbers.at(20) << std::endl;//
	//at()�������������Ƿ�Խ�磬���Խ����׳��쳣, []�����������Ƿ�Խ�磬���Խ��ᵼ��δ������Ϊ, ����at()����ȫ, atԽ�緵��

    // ����Ԫ��
    std::cout << "Elements in the vector and every+1: ";
	// ʹ�÷�Χ for ѭ������Ԫ��, �� C++11 ��ʼ֧�֣����ڱ���������int num ��һ����ʱ���������ڴ洢�����е�Ԫ�أ�numbers ��������int& num�ô����벻�������ʱ������Ч�ʸ��ߣ����ҿ����޸������е�Ԫ��
    for (int &num : numbers) {
        num = num + 1;
        std::cout << num << " ";
		
    }
    std::cout << std::endl;

	// ʹ�õ���������Ԫ�أ���������һ��ָ��������Ԫ�ص�ָ�룬�������ڱ��������е�Ԫ��
	//�ŵ㣺���Ա���������������������vector�����ҿ��Ա���map��set�ȣ����ҿ����޸������е�Ԫ�أ�
	//ȱ�㣺����ȽϷ���
    std::cout << "Elements in the vector (using iterator): ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // ��ȡռ���ڴ��С
    std::cout << "Size of the vector: " << numbers.size() << std::endl;

	// ����Ƿ�Ϊ�գ����Ϊ�շ��� true�����򷵻� false
    std::cout << "Is the vector empty? " << (numbers.empty() ? "Yes" : "No") << std::endl;

	// ɾ��Ԫ�أ�erase(),���������ǵ�������ɾ��������ָ���Ԫ��,erase()���ص�����һ��Ԫ�صĵ�����,ɾ������Ԫ�ؿ���ʹ��clear()
    numbers.erase(numbers.begin() + 1); // ɾ������1����Ԫ��

    // ����
	std::cout << "Number by sort:" ;
    std::sort(numbers.begin(), numbers.end());
	std::cout << numbers << std::endl;
	// ����Ԫ��,find()���ص��ǵ�����������ҵ�����Ԫ�صĵ����������򷵻�������end()������
    auto it = std::find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        std::cout << "Element 8 found at index: " << std::distance(numbers.begin(), it) << std::endl;
    }
    else {
        std::cout << "Element 8 not found" << std::endl;
    }

    // ��ת
    std::reverse(numbers.begin(), numbers.end());
	std::cout << numbers << std::endl;
    // ����Ԫ��
    std::cout << "Elements in the vector after reverse: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ��� vector
    numbers.clear();
    std::cout << "Size of the vector after clear: " << numbers.size() << std::endl;


	std::vector<Vertex> vertices;
    
	vertices.push_back(Vertex(1, 2, 3));
    //��һ��push��	Vertex(1, 2, 3) �����������Ƶ� vertices �С����ø��ƹ��캯�� 1 ��
	vertices.push_back(Vertex(4, 5, 6));
    //���ڵ�ǰ����Ϊ 1��std::vector ��Ҫ��չ������ͨ������£�std::vector �Ὣ��������������������һ������Ϊ 2 �����ڴ�顣���е�Ԫ�� Vertex(1, 2, 3) �����Ƶ��µ��ڴ���С�Vertex(4, 5, 6) �����������Ƶ� vertices �С����ø��ƹ��캯�� 2 �Σ�1 �����ڸ�������Ԫ�أ�1 ��������Ԫ�أ���
	vertices.push_back(Vertex(7, 8, 9));
    //���ڵ�ǰ����Ϊ 2��std::vector ��Ҫ�ٴ���չ������ͨ������£�std::vector �Ὣ��������������������һ������Ϊ 4 �����ڴ�顣���е�Ԫ�� Vertex(1, 2, 3) �� Vertex(4, 5, 6) �����Ƶ��µ��ڴ���С�Vertex(7, 8, 9) �����������Ƶ� vertices �С����ø��ƹ��캯�� 3 �Σ�2 �����ڸ�������Ԫ�أ�1 ��������Ԫ�أ�
    //һ��1+2+3=6
	std::cout << "Vertices:" << std::endl;
	vertices.clear();
    //�Ż���
    std::vector<Vertex> vertices4;
    //
    vertices4.reserve(3); // Ԥ�ȷ����㹻�Ŀռ䣬��������չ
	//push_back()����������Ҫʱ��չ����������ܻᵼ�¶���ڴ�����Ԫ�ظ��ơ������֪��Ҫ��ӵ�Ԫ������������ʹ�� reserve() ����Ԥ�ȷ����㹻�Ŀռ䣬��������չ��
	//emplace_back()��������������ĩβֱ�ӹ���Ԫ�أ��������ȴ���һ����ʱ����Ȼ���ٸ��Ƶ������С��������Ա������ĸ��Ʋ�����������ܡ�
    vertices4.emplace_back(1, 2, 3);
    vertices4.emplace_back(4, 5, 6);
    vertices4.emplace_back(7, 8, 9);
	//���ù��캯�� 3 ��,û�е��ø��ƹ��캯��
    vertices4.clear();
	
   

	std::cout << "start reserve" << std::endl;
    // ʹ�� reserve ����
    std::vector<Vertex> vertices3;
    vertices3.reserve(3); // Ԥ�ȷ����ڴ棬������ʼ��Ԫ�أ�����������Ϊ 3�������ڴ��СΪ 0,���ù��캯�� 0 ��
    std::cout << "After reserve, size: " << vertices3.size() << ", capacity: " << vertices3.capacity() << std::endl;

    vertices3.push_back(Vertex(1, 2, 3));
    vertices3.push_back(Vertex(4, 5, 6));
    vertices3.push_back(Vertex(7, 8, 9));
    std::cout << "After push_back, size: " << vertices3.size() << ", capacity: " << vertices3.capacity() << std::endl;

    // ʹ�ô��г�ʼ��С�Ĺ��캯��
    std::vector<Vertex> vertices2(3); // �����ڴ沢��ʼ��3��Ԫ�أ�����Ĭ�Ϲ��캯�� 3 ��
    std::cout << "After constructor, size: " << vertices2.size() << ", capacity: " << vertices2.capacity() << std::endl;

    vertices2[0] = Vertex(1, 2, 3);
    vertices2[1] = Vertex(4, 5, 6);
    vertices2[2] = Vertex(7, 8, 9);
    std::cout << "After assignment, size: " << vertices2.size() << ", capacity: " << vertices2.capacity() << std::endl;

  


	std::cin.get();











    return 0;
}

