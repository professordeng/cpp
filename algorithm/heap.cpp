// ʹ�� algorithm ��ĶѲ��� 

#include <iostream>
#include <algorithm>
#include <vector>

int main(){
	std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 	
 	// �����������ܳ�Ϊ�ѵ���������У��Ӳ����������
	auto heap_end = std::is_heap_until(v.begin(), v.end());
	std::cout << "only heap: ";
	for (auto i = v.begin(); i != heap_end; ++i) std::cout << *i << ' ';
    std::cout << '\n';
 	
 	// �ж��Ƿ�Ϊ�� 
    if (!std::is_heap(v.begin(), v.end())) {
        std::cout << "making heap...\n";
        std::make_heap(v.begin(), v.end());
    } 
    
 	// �������� 
    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
    // ���������Ԫ�أ�����ӵ����Ȼ�󹹽� 
    v.push_back(6); 
    std::push_heap(v.begin(), v.end());
    std::cout << "after push_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
    // �Ƚ����ƶ������Ȼ��ɾ��
	std::pop_heap(v.begin(), v.end());
	v.pop_back(); 
	std::cout << "after pop_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
    // �����ж����Ե�����������������û�ж����� 
	std::sort_heap(v.begin(), v.end()); 
    std::cout << "after sort_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
    
	return 0;
} 
