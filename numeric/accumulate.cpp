// 数值运算

#include <iostream>
#include <numeric>
#include <vector> 

int main() {
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = std::accumulate(v.begin(), v.end(), 0);  // 求和,初值为 0 
	std::cout << sum << std::endl;
	return 0;
} 
