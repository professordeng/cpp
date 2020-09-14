/*
 * author: professordeng
 * description: ��ϵ regex ��� regex_match ����
 * note: regex_match ��ֻ�ɹ���ƥ��������ʽ�������ַ����У��� std::regex_search ���ɹ���ƥ�������С�
*/

#include <iostream>
#include <string>
#include <regex>

int main()
{
	// ��������ʽƥ��
	std::string fnames[] = {"foo.txt", "bar.txt", "baz.dat", "zoidberg"};
	std::regex txt_regex("[a-z]+\\.txt");          
	
	for (const auto &fname : fnames) {
	    std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
	}

	// ��ȡ��ƥ��
	std::regex base_regex("([a-z]+)\\.txt");
	std::smatch base_match;
	for (const auto &fname : fnames) {
		if (std::regex_match(fname, base_match, base_regex)) {
			// �׸� sub_match �������ַ���
			// �¸� sub_match ���׸������ű��ʽ��
			if (base_match.size() == 2) {
				std::ssub_match base_sub_match = base_match[1];
				std::string base = base_sub_match.str();
				std::cout << fname << " has a base of " << base << '\n';
			}
		}
	}

	// ��ȡ������ƥ��
	std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
	std::smatch pieces_match;
	for (const auto &fname : fnames) {
		if (std::regex_match(fname, pieces_match, pieces_regex)) {
			std::cout << fname << '\n';
			for (size_t i = 0; i < pieces_match.size(); ++i) {
				std::ssub_match sub_match = pieces_match[i];
				std::string piece = sub_match.str();
				std::cout << "  submatch " << i << ": " << piece << '\n';
			}
		}
	}
}

