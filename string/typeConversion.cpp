// ��ֵ�������ֵ�͵�ת��

#include <iostream>
#include <string>

int main() {
	// string ���� 
	std::string pi = "3.14";
	std::cout << std::stoi(pi) << std::endl;
	std::cout << std::stof(pi) << std::endl;  // ���� stod 
	
	// char ָ������
	const char *e = "2.7";
	std::cout << std::atoi(e) << std::endl;
	std::cout << std::atol(e) << std::endl;  // ���� atoll 
	return 0;
} 
