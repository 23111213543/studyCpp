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
	//�����Ԫ������һ�����ص�<<����������ڽ�String�����������׼���������std::cout����
	// ������˵����δ���������һ����Ԫ������ʹ��std::ostream& operator<<(std::ostream& stream, const String& string)���Է���String���˽�г�Աm_Buffer��
	// ����������ʹ��std::cout << stringObject; ʱ���������������Ԫ��������String������������������̨
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	
	//����[]�����
	//����[]�������Ŀ������String��Ķ������������һ��ʹ���±������[]��
	// ���磬�������һ��String����string�������ʹ��string[0]�������ַ����ĵ�һ���ַ���
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
	//�������캯����һ������Ĺ��캯�������ڴ�������ʱ��ʹ��ͬһ�����һ����������ʼ���¶���

	//�������캯��ͨ�����ڣ�
		//1. ͨ��ʹ����һ��ͬ���͵Ķ�������ʼ���´����Ķ���
		//2. ���ƶ��������Ϊ�������ݸ�������
		//3. ���ƶ��󣬲��Ӻ��������������
	//�������캯���������Ͷ������£�
	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "Copied String!" << std::endl;	
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		m_Buffer[m_Size] = 0;
	}
	//String(const String& other)=delete; //���ÿ������캯��,�����Ͳ���ֱ�Ӹ���string��second
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}
//���������������&���Ḵ��һ�Σ��ⲿ��second���Ƹ��ڲ�����string������ʱ��������
void PrintString(const String& string)
{
	std::cout << string << std::endl;
}
int main() {
	String string = "Cherno";
	//ֱ�Ӹ���string��second�������������ԭ���� String ��û��ʵ����ȷ�Ŀ������캯�������� m_Buffer ָ�뱻ǳ����������������������ʱ���᳢��ɾ��ͬһ���ڴ����Σ��Ӷ�����˫��ɾ������
	//���������Ϊ��
		//1.	Ĭ�ϵĿ������캯����ʹ�ã����� m_Buffer ָ�������ǳ������
		//2.	�� second ��Ϊ string �ĸ�������ʱ��������������ͬһ�� m_Buffer ָ�롣
		//3.	�� string �� second ����������������ʱ�����Ƕ�����ɾ��ͬһ���ڴ棬����˫��ɾ����
	//����������ķ�����ʵ��һ����ȷ�Ŀ������캯��������Ϊ second ����һ���µ��ڴ�飬���� string �����ݸ��Ƶ�����µ��ڴ���С�
	//�������� string �� second ������ʱ�����ǻ�ֱ�ɾ�����Ե��ڴ�飬�����ᵼ��˫��ɾ������
	String second = string;

	//second[2]= 'a'; �Ⱥ��ұ���һ��char���ͣ������char*���ͣ�
	second[2] = 'a';
	//���û�е��ÿ������캯������Ϊ�����ֱ�Ӹ�ֵ�����ǳ�ʼ��

	PrintString(string);
	PrintString(second);
	
	std::cin.get();
	
}