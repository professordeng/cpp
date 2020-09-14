//  划分操作 partition 
// partition(first, last, plicy)  
#include <iostream>
#include <algorithm>

 
int main(){
	std::vector<int> v = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
	int pivot = 4;
	// 使得谓词 p 对其返回 true 的元素前于谓词 p 对其返回 false 的元素。不保持相对顺序。
	// 返回指向第二组元素首元素的迭代器。
	auto it = partition(v.begin(), v.end(), [pivot](const int& em){
		return em < pivot;
	});
	for(auto& a : v) std::cout << a << " ";
	std::cout << std::endl; 
	return 0;
}
