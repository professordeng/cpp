/* 容器库， 
	1. 容器库是类模板与算法的汇集
	2. 允许程序员快速调用常用数据结构
	3. 三大类容器 : 顺序容器、关联容器和无序关联容器
	容器管理包括为元素分配存储空间，提供相应方法访问元素 
*/ 

// ------------  顺序容器-----------------------

// 1. 静态的连续数组
#include <array>

std::array<int, 3> a = {1, 2, 3};
a.back();    // 返回最后一个元素 
a.front();   // 返回第一个元素
a[1];  // 按下标访问

// 2. 动态的连续数组
#include <vector>

std::vector<int> v = {7, 5, 16, 8};
v.push_back(25); // 添加元素到末尾
v.front();       // 访问第一个元素
v.back();        // 访问最后一个元素

v.begin();       // 返回指向容量第一个元素的迭代器
v.end();         // 返回指向容量最后一个元素的迭代器

v.empty();       // 判断容量是否为空
v.size();        // 已有元素个数

v.clear();        // 清空内容
v.insert(2, 8);   // 在某个位置插入元素
v.erase(v.begin(),v.end());  // 清除一段元素
v.emplace_back(5);  // 元素末尾的实际内存直接添加元素
v.pop_back();       // 移除末元素

// 3. 双端队列
#include<deque>

std::deque<int> d = {7, 5, 16 8};
d.front();  // 访问第一个元素
d.back();   // 访问最后一个元素
d.empty();  // 检测容器是否为空
d.size();   // 返回容器的已有元素个数
d.clear();  // 清空队列
d.push_back(8);  // 从后方添加元素
d.push_front(8); // 从前方添加元素
d.pop_back();    // 从后方弹出元素
d.pop_front();   // 从前方弹出元素

// 4. 双链表
#include <list>

std::list<int> l = {7, 5, 16, 8};
l.front();  // 访问第一个元素
l.back();   // 访问最后一个元素
l.begin();  // 指向第一个元素的迭代器
l.end();    // 指向最后一个元素的迭代器
l.empty();  // 是否为空
l.size();   // 已有元素个数
l.clear();  // 清空链表
l.emplace_back(6);  // 从后方就地添加元素
l.pop_back(); 
l.emplace_front(7);
l.pop_front();
l.insert(l.end(), 8); // 在某个迭代器之前插入一个结点
l.erase(l.begin(), 1); // 删除从某个迭代器开始的 n 个结点 
l.sort();   // 从小到大排序
l.sort(std::greater<int>());   
l.unique();  // 删除连续的重复元素 
l.merge(lx); // 合并两个已排序列表 

//----------------- 关联容器 ------------------------

// 1. 唯一键的集合，按照键排序
#include <set>

std::set<int> s = {1, 2, 3, 4};
s.find(2);    // 返回一个迭代器指针
s.insert(5);  // 插入元素 
s.clear();    // 清空元素
s.erase(4);   // 清除元素
s.empty();

// 2. 键值对的集合，按照键排序，键是唯一的
#include <map>

std::map<int, char> m = {{1, 'a'}, {2, 'b'}};
m.find(2);
m.empty();
m.erase(2);  // 根据键值删除
m.size();    // 已有元素个数
m.insert({3, 'c'});  // 插入元素
m[4] = 'd';   // 插入元素

//------------无序关联容器----------------------- 

// 1. 唯一键的集合 
#include <unordered_set>

// 2. 键值对的集合
#include <unordered_map> 
 

 
 
