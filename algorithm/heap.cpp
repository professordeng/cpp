// 使用 algorithm 库的堆操作 

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 	
 	// 查找数组中能成为堆的最大子序列，从查找起点算起
	auto heap_end = std::is_heap_until(v.begin(), v.end());
	std::cout << "only heap: ";
	for (auto i = v.begin(); i != heap_end; ++i) std::cout << *i << ' ';
    std::cout << '\n';
 	
 	// 判断是否为堆 
    if (!std::is_heap(v.begin(), v.end())) {
        std::cout << "making heap...\n";
        std::make_heap(v.begin(), v.end());
    } 
    
 	// 建立最大堆 
    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
    // 向最大堆添加元素，先添加到最后，然后构建 
    v.push_back(6); 
    std::push_heap(v.begin(), v.end());
    std::cout << "after push_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
    // 先将根移动到最后，然后删除
	std::pop_heap(v.begin(), v.end());
	v.pop_back(); 
	std::cout << "after pop_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
    // 将已有堆属性的数组进行排序，排完后没有堆属性 
	std::sort_heap(v.begin(), v.end()); 
    std::cout << "after sort_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
	return 0;
} 
