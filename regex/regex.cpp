/*
 * author: professordeng
 * description: ѧϰʹ�� regex ��
 * �ο����ף�https://zh.cppreference.com/w/cpp/regex
 */

#include <iostream>
#include <iterator>
#include <string>
#include <regex>

int main(){

	// �������ַ���
	std::string s = "Some people, when confronted with a problem, think "
		            "\"I know, I'll use regular expressions.\" "
				    "Now they have two problems.";
	// ƥ��ģʽ��C++ Ĭ�ϵ�������ʽΪ ECMAScript ��ʽ�������ִ�Сд
	std::regex self_regex("REGULAR EXPRESSIONS", std::regex_constants::ECMAScript | std::regex_constants::icase);
	// ����ַ����г���ƥ�䷵�� true
	if(std::regex_search(s, self_regex)){
		std::cout<< "Text contains the phrase 'regular expressions'\n";
	}
	
	// �ո񡢻س���Ϊ�ָ������ַ������зָ�
	std::regex word_regex("(\\S+)");

	// sregex_iterator �ǵ��������ҵ�����ƥ���Ӵ�������Ҫ��֤ word_regex ���������ڱȵ���������Ҳ����Ҫ�����涨������
	auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();

	// distance ����������е�Ԫ�ظ���
	std::cout << "Found "
			  << std::distance(words_begin, words_end)
			  << " words\n";

	// �ҳ����ȴ��� 6 �ĵ���
	const int N = 6;
	std::cout << "Words longer than " << N << " characters:\n";
	for(std::sregex_iterator i = words_begin; i != words_end; i++){
		// ����ָ��ָ�� smatch ����
		std::smatch match = *i; 
		// �� smatch ����ת��Ϊ string ����
		std::string match_str = match.str();
		// ���ƥ����Ӵ����� N �����
		if(match_str.size() > N){
			std::cout<<"  "<<match_str<<'\n';		
		}
	}

	// ƥ����ڵ��� 7 �ĵ��� ������[]
	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';
	return 0;
}







