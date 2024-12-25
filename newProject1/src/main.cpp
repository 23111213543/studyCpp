#include <iostream>
#include <vector>
#include <algorithm> 
//宏macro：实际上是一个查找替换的过程，编译器会在编译之前将宏替换为对应的内容
//宏定义的格式：#define 宏名 宏体
//1.	对象宏（Object-like Macros）：用于定义常量或简单的文本替换
#define WAIT std::cin.get()
#define Print(x) std::cout << x << std::endl


//2.	函数宏（Function-like Macros）：用于定义带参数的宏
#define SQUARE(x) ((x) * (x))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//3.	条件编译（Conditional Compilation）：用于根据条件编译代码, “定义在项目属性中，C++预处理器中” 包含ifdef，
#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif
//endif 与 ifdef 之间的代码只有在 DEBUG 被定义的情况下才会被编译，否则会被忽略

//4.	#include 指令：用于包含头文件
//#include <iostream>
//#include "myheader.h"

//5.	#undef 指令：用于取消宏定义
//#undef MAX

//6.预定义宏（Predefined Macros）：由编译器预定义的宏
//__LINE__：当前源文件的行号
//__FILE__：当前源文件的文件名
 //__DATE__：当前编译日期
//__TIME__：当前编译时间
//__cplusplus：当前编译器是否支持 C++ 标准，__cplusplus 是一个数字，表示 C++ 标准的年份
//__STDC__：当前编译器是否支持 C 标准
//__STDC_HOSTED__：当前编译器是否运行在宿主环境，宿主环境是指完整的操作系统环境
//__STDC_VERSION__：当前编译器所支持的 C 标准版本
//__STDCPP_STRICT_POINTER_SAFETY__：当前编译器是否支持严格指针安全
//__STDCPP_THREADS__：当前编译器是否支持多线程

//__STDC_ISO_10646__：当前编译器是否支持 ISO 10646 字符集
//__STDC_MB_MIGHT_NEQ_WC__：当前编译器是否支持多字节字符集
//__STDCPP_DEFAULT_NEW_ALIGNMENT__：当前编译器默认的 new 对齐方式




int main() {

    Print("Hello World!");
    std::cout << "当前文件名: " << __FILE__ << std::endl;
    std::cout << "当前行号: " << __LINE__ << std::endl;
    std::cout << "编译日期: " << __DATE__ << std::endl;
    std::cout << "编译时间: " << __TIME__ << std::endl;
	std::cout << "C++标准年份: " << __cplusplus << std::endl; //199711

	std::cout << "是否支持多线程: " << __STDCPP_THREADS__ << std::endl;//1表示支持多线程


	WAIT;//不建议这样改变代码的执行流程，这样会让代码变得难以理解
};
    
    

