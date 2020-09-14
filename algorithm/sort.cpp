// 使用 algorithm 库的排序算法 

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	std::vector<int> v = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
	// 升序 
	std::sort(v.begin(), v.end());
	for(auto a : v) {
		std::cout << a << " "; 
	}
	std::cout << std::endl;
	
	// 降序 
	std::sort(v.begin(), v.end(), std::greater<int>()); 
	for(auto a : v) {
		std::cout << a << " "; 
	}
	std::cout << std::endl;
	
	// 自定义
	std::sort(v.begin(), v.end(), [](int a, int b){
		return b < 2*a;     // 按某规则进行排序 
	}); 
	for(auto a : v) {
		std::cout << a << " "; 
	}
	std::cout << std::endl;
	return 0;
} 
