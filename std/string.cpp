//   �ַ����� 

#include <string>

std::string s = "professordeng";
std::string sx = " hello";
s.front();  // ����ĸ
s.back();   // β��ĸ
s[0];       // ��������
s.length(); // ����
s.insert(0, sx); // ����
s.pop_back();     // ɾ��ĳ�ַ� 
s.push_back('a');  
s.substr(2, 3);  // �� 2 ��ʼ����Ϊ 3
s.replace(2, 5, "red"); // �� 2 ��ʼ��Ϊ 5 �Ĵ����滻Ϊ red 
s.find('o');  // �ַ� o �״γ��ֵ�λ�� 
s.find('o', 2); // �� 2 ��λ�ÿ�ʼ�� 
s.find_first_of('o'); // �ַ� o �״γ��ֵĵط���
std::stoi(sx);  // �ַ�ת���� 
std::stof(sx);  // �ַ�ת������ 
 
