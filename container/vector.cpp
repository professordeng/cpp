// vector ��ʹ��
// ��̬���������ڴ�ռ������ 

#include <iostream>
#include <algorithm> 
#include <vector>

int main() {
	std::vector<int> v = {2,4,5,8,3,1,7,9,6};
	
	std::sort(v.begin(), v.end());  // ����
	 
	// ֱ�ӱ��� 
	for(auto& i : v) 
		std::cout << i << " ";
	std::cout << std::endl; 
	
	// ����������
	for(auto it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// ������������� 
	for(auto it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return 0; 
} 
