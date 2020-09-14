// 数值型与非数值型的转换

#include <iostream>
#include <string>

int main() {
	// string 类型 
	std::string pi = "3.14";
	std::cout << std::stoi(pi) << std::endl;
	std::cout << std::stof(pi) << std::endl;  // 还有 stod 
	
	// char 指针类型
	const char *e = "2.7";
	std::cout << std::atoi(e) << std::endl;
	std::cout << std::atol(e) << std::endl;  // 还有 atoll 
	return 0;
} 
