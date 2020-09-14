/* 
 * author: professordeng
 * description: 利用指针修改 const 变量在内存中的值
 */ 

#include <iostream>
#include <string>

int main()
{
	const int MAX_AGE = 9;
	int* a = (int*)&MAX_AGE;
	*a = 8;
	std::cout << MAX_AGE << std::endl;
	std::cout << &MAX_AGE << std::endl;
	std::cout << a << std::endl;
	std::cout << *a << std::endl;
	return 0;
}

