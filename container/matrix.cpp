// ���� vector Ƕ�׹������ 

#include <iostream>
#include <vector>

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<std::vector<int>> matrix(N);   // �ȿ��� N �� 
	for(int i = 0; i < N; i ++) matrix[i].resize(M); // ÿ���� M ��Ԫ��
	
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < matrix.size(); j++) {
			matrix[i][j] = i*j;
		}
	} 
	for(auto& row : matrix) {
		for(auto& em : row) {
			std::cout << em << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
