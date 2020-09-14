/*
 * author: professordeng
 * description: 测试 algorithm 库的 equal 函数
 *              equal 函数的实现依赖于迭代器，通过比较某个范围的数据得出结果
 * reference: https://zh.cppreference.com/w/cpp/algorithm/equal
 */

#include <iostream>
#include <algorithm>
#include <string>
 
// 利用 equal 函数判断字符串是否是回文串。
// 这里用到了 string 的迭代器,迭代范围是 s.begin 到 s.begin+s.size/2，第三个参数是另一个开始的地方，我们用到了方向迭代
void test(const std::string& s)
{
	if(std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin())) {
		std::cout << "\"" << s << "\" is a palindrome\n";
	} else {
		std::cout << "\"" << s << "\" is not a palindrome\n";
	}
}
int main()
{
	test("radar");
	test("abba");
	test("hello");
}
