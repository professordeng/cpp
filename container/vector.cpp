// vector 的使用
// 动态分配连续内存空间的容器 

#include <iostream>
#include <algorithm> 
#include <vector>

int main() {
	std::vector<int> v = {2,4,5,8,3,1,7,9,6};
	
	std::sort(v.begin(), v.end());  // 排序
	 
	// 直接遍历 
	for(auto& i : v) 
		std::cout << i << " ";
	std::cout << std::endl; 
	
	// 迭代器遍历
	for(auto it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// 迭代器反向遍历 
	for(auto it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0; 
} 
