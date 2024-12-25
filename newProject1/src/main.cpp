#include <iostream>
#include <vector>
#include <algorithm> 

struct Vector3
{
	float   a, b, c;
	Vector3 ()
		: a(8), b(9), c(10) {}

};

int main() {
    
    {
        
		{
			//栈stack的存储位置都是连续  
			int value = 5;
			int array[5] = { 1, 2, 3, 4, 5 };
			Vector3  vector;
		}
         
		
		//堆heap的存储位置不是连续的
		int* hvalue = new int;  
        *hvalue = 5;
		int* harray = new int[5];
		harray[0] = 1;
		harray[1] = 2;
		harray[3] = 3;
		harray[4] = 4;
		
		
		Vector3* hvector = new Vector3();
		//delete释放内存
		delete hvalue;
		delete[] harray;
		delete hvector;
    }

	std::cin.get();

    return 0;
}

