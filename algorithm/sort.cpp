// ʹ�� algorithm ��������㷨 

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	std::vector<int> v = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
	// ���� 
	std::sort(v.begin(), v.end());
	for(auto a : v) {
		std::cout << a << " "; 
	}
	std::cout << std::endl;
	
	// ���� 
	std::sort(v.begin(), v.end(), std::greater<int>()); 
	for(auto a : v) {
		std::cout << a << " "; 
	}
	std::cout << std::endl;
	
	// �Զ���
	std::sort(v.begin(), v.end(), [](int a, int b){
		return b < 2*a;     // ��ĳ����������� 
	}); 
	for(auto a : v) {
		std::cout << a << " "; 
	}
	std::cout << std::endl;
	return 0;
} 
