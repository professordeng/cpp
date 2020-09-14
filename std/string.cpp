//   字符串库 

#include <string>

std::string s = "professordeng";
std::string sx = " hello";
s.front();  // 首字母
s.back();   // 尾字母
s[0];       // 索引访问
s.length(); // 串长
s.insert(0, sx); // 插入
s.pop_back();     // 删除某字符 
s.push_back('a');  
s.substr(2, 3);  // 从 2 开始长度为 3
s.replace(2, 5, "red"); // 从 2 开始长为 5 的串被替换为 red 
s.find('o');  // 字符 o 首次出现的位置 
s.find('o', 2); // 从 2 的位置开始找 
s.find_first_of('o'); // 字符 o 首次出现的地方。
std::stoi(sx);  // 字符转整型 
std::stof(sx);  // 字符转浮点型 
 
