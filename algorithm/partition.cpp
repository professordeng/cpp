//  ���ֲ��� partition 
// partition(first, last, plicy)  
#include <iostream>
#include <algorithm>

 
int main(){
	std::vector<int> v = {1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
	int pivot = 4;
	// ʹ��ν�� p ���䷵�� true ��Ԫ��ǰ��ν�� p ���䷵�� false ��Ԫ�ء����������˳��
	// ����ָ��ڶ���Ԫ����Ԫ�صĵ�������
	auto it = partition(v.begin(), v.end(), [pivot](const int& em){
		return em < pivot;
	});
	for(auto& a : v) std::cout << a << " ";
	std::cout << std::endl; 
	return 0;
}
