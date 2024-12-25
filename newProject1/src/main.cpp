#include <iostream>
#include <vector>
#include <algorithm> 
//��macro��ʵ������һ�������滻�Ĺ��̣����������ڱ���֮ǰ�����滻Ϊ��Ӧ������
//�궨��ĸ�ʽ��#define ���� ����
//1.	����꣨Object-like Macros�������ڶ��峣����򵥵��ı��滻
#define WAIT std::cin.get()
#define Print(x) std::cout << x << std::endl


//2.	�����꣨Function-like Macros�������ڶ���������ĺ�
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//3.	�������루Conditional Compilation�������ڸ��������������, ����������Ŀ�����У�C++Ԥ�������С� ����ifdef��
#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif
//endif �� ifdef ֮��Ĵ���ֻ���� DEBUG �����������²Żᱻ���룬����ᱻ����

//4.	#include ָ����ڰ���ͷ�ļ�
//#include <iostream>
//#include "myheader.h"

//5.	#undef ָ�����ȡ���궨��
//#undef MAX

//6.Ԥ����꣨Predefined Macros�����ɱ�����Ԥ����ĺ�
//__LINE__����ǰԴ�ļ����к�
//__FILE__����ǰԴ�ļ����ļ���
 //__DATE__����ǰ��������
//__TIME__����ǰ����ʱ��
//__cplusplus����ǰ�������Ƿ�֧�� C++ ��׼��__cplusplus ��һ�����֣���ʾ C++ ��׼�����
//__STDC__����ǰ�������Ƿ�֧�� C ��׼
//__STDC_HOSTED__����ǰ�������Ƿ���������������������������ָ�����Ĳ���ϵͳ����
//__STDC_VERSION__����ǰ��������֧�ֵ� C ��׼�汾
//__STDCPP_STRICT_POINTER_SAFETY__����ǰ�������Ƿ�֧���ϸ�ָ�밲ȫ
//__STDCPP_THREADS__����ǰ�������Ƿ�֧�ֶ��߳�

//__STDC_ISO_10646__����ǰ�������Ƿ�֧�� ISO 10646 �ַ���
//__STDC_MB_MIGHT_NEQ_WC__����ǰ�������Ƿ�֧�ֶ��ֽ��ַ���
//__STDCPP_DEFAULT_NEW_ALIGNMENT__����ǰ������Ĭ�ϵ� new ���뷽ʽ




int main() {

    Print("Hello World!");
    std::cout << "��ǰ�ļ���: " << __FILE__ << std::endl;
    std::cout << "��ǰ�к�: " << __LINE__ << std::endl;
    std::cout << "��������: " << __DATE__ << std::endl;
    std::cout << "����ʱ��: " << __TIME__ << std::endl;
	std::cout << "C++��׼���: " << __cplusplus << std::endl; //199711

	std::cout << "�Ƿ�֧�ֶ��߳�: " << __STDCPP_THREADS__ << std::endl;//1��ʾ֧�ֶ��߳�


	WAIT;//�����������ı�����ִ�����̣��������ô������������
};
    
    

