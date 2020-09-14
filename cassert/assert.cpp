/* 
 * author: professordeng
 * description: 宏函数，若用户制定的条件非 true	则中断程序
 */

#include <iostream>
// 去注释化则禁用 assert()
// #define NDEBUG
#include <cassert>
  
int main()
{
	assert(2+2==4);
	std::cout << "Execution continues past the first assert\n";
    assert(2+2==5);
	std::cout << "Execution continues past the second assert\n";
}
