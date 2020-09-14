/*
 * author: professordeng
 * description: ���� algorithm ��� equal ����
 *              equal ������ʵ�������ڵ�������ͨ���Ƚ�ĳ����Χ�����ݵó����
 * reference: https://zh.cppreference.com/w/cpp/algorithm/equal
 */

#include <iostream>
#include <algorithm>
#include <string>
 
// ���� equal �����ж��ַ����Ƿ��ǻ��Ĵ���
// �����õ��� string �ĵ�����,������Χ�� s.begin �� s.begin+s.size/2����������������һ����ʼ�ĵط��������õ��˷������
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
