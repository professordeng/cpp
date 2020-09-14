/*
 * author: professordeng
 * description: 学习使用 regex 库
 * 参考文献：https://zh.cppreference.com/w/cpp/regex
 */

#include <iostream>
#include <iterator>
#include <string>
#include <regex>

int main(){

	// 待处理字符串
	std::string s = "Some people, when confronted with a problem, think "
		            "\"I know, I'll use regular expressions.\" "
				    "Now they have two problems.";
	// 匹配模式，C++ 默认的正则表达式为 ECMAScript 格式，不区分大小写
	std::regex self_regex("REGULAR EXPRESSIONS", std::regex_constants::ECMAScript | std::regex_constants::icase);
	// 如果字符串中出现匹配返回 true
	if(std::regex_search(s, self_regex)){
		std::cout<< "Text contains the phrase 'regular expressions'\n";
	}
	
	// 空格、回车作为分隔符对字符串进行分割
	std::regex word_regex("(\\S+)");

	// sregex_iterator 是迭代器，找到所有匹配子串，这里要保证 word_regex 的生存周期比迭代器长，也就是要在外面定义再用
	auto words_begin = std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();

	// distance 求出迭代器中的元素个数
	std::cout << "Found "
			  << std::distance(words_begin, words_end)
			  << " words\n";

	// 找出长度大于 6 的单词
	const int N = 6;
	std::cout << "Words longer than " << N << " characters:\n";
	for(std::sregex_iterator i = words_begin; i != words_end; i++){
		// 迭代指针指向 smatch 对象
		std::smatch match = *i; 
		// 将 smatch 对象转化为 string 类型
		std::string match_str = match.str();
		// 如果匹配的子串大于 N ，输出
		if(match_str.size() > N){
			std::cout<<"  "<<match_str<<'\n';		
		}
	}

	// 匹配大于等于 7 的单词 并加上[]
	std::regex long_word_regex("(\\w{7,})");
	std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
	std::cout << new_s << '\n';
	return 0;
}







