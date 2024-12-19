#include <iostream>

class Base {
public:
    Base(int value) {
        std::cout << "Base initialized with value: " << value << std::endl;
    }
};

class MyClass : public Base {
private:
    const int m_ConstValue;
    int m_X;
    int m_Y;
public:
    // ʹ�ó�ʼ���б�
	// ��ʼ���б���﷨���ڹ��캯���Ĳ����б����ʹ��ð�ţ�:�����г�ʼ���б�Ȼ���ڳ�ʼ���б����Զ��ŷָ�����ʽ��ʼ����Ա����
	// ��ʼ���б���ŵ㣺��ʼ���б���Ա�֤��Ա�����ĳ�ʼ��˳�򣬱����˳�Ա������ʼ��˳��ȷ��������
	//��ʼ���б���﷨���ڹ��캯���Ĳ����б����ʹ��ð�ţ�:�����г�ʼ���б�Ȼ���ڳ�ʼ���б����Զ��ŷָ�����ʽ��ʼ����Ա����
	//��ʼ���б��Ч�ʣ���ʼ���б��Ч��Ҫ�����ڹ��캯�����ڽ��и�ֵ��������Ϊ��ʼ���б���ֱ�ӳ�ʼ����Ա��������������Ĭ�Ϲ����ٸ�ֵ
	//���������ó�Ա��������Ա�����ó�Աֻ���ڳ�ʼ���б��н��г�ʼ���������ڹ��캯�����ڽ��и�ֵ����
	//�����ʼ����������Ĺ��캯�������ڹ��캯�����ڵ��û���Ĺ��캯��������ʹ�ó�ʼ���б�
    MyClass(int x, int y, int constValue)
		: Base(x + y), m_ConstValue(constValue), m_X(x), m_Y(y) {
        std::cout << "MyClass initialized using initialization list" << std::endl;
        std::cout << "m_ConstValue:"<<m_ConstValue << std::endl;
		std::cout << "m_X:" << m_X << std::endl;
		std::cout << "m_Y:" << m_Y << std::endl;
    }

    // �ڹ��캯������ʹ�� this-> ���г�ʼ��
	// ע�⣺���ַ�ʽ�������ʵ������Ϊ�ڹ��캯������ʹ�� this-> ���г�ʼ���ᵼ�³�Ա�����ĳ�ʼ��˳��ȷ��
	// ���磺m_ConstValue ���� m_X �� m_Y ֮ǰ��ʼ��
	// �����ڳ�ʼ���б��У���Ա�����ĳ�ʼ��˳����ȷ����
	// ���ԣ����ʵ����ʹ�ó�ʼ���б���г�ʼ��
    //Ч�ʽϵͣ��ڹ��캯�����ڽ��и�ֵ��������Ա�������ȱ�Ĭ�Ϲ��죬Ȼ���ٸ�ֵ�����ܻᵼ�²���Ҫ�����ܿ�����
    //������Ա�����ó�Ա��������Ա�����ó�Ա�����ڹ��캯�����ڽ��и�ֵ��ʼ��������ʹ�ó�ʼ���б�
    //�����ʼ����������Ĺ��캯�������ڹ��캯�����ڵ��û���Ĺ��캯��������ʹ�ó�ʼ���б�
    MyClass(int x, int y) : Base(x + y), m_ConstValue(0) {
        this->m_X = x;
        this->m_Y = y;
        std::cout << "MyClass initialized using this-> in constructor body" << std::endl;
		std::cout << "m_ConstValue:" << m_ConstValue << std::endl;
		std::cout << "m_X:" << m_X << std::endl;
		std::cout << "m_Y:" << m_Y << std::endl;
    }
};

int main() {
    MyClass obj1(1, 2, 3); // ʹ�ó�ʼ���б�
    MyClass obj2(4, 5);    // �ڹ��캯������ʹ�� this-> ���г�ʼ��

    return 0;
}
