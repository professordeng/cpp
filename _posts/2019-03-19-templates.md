---
title: c++ 模板
---

学 JAVA 的人应该知道泛型（generic），但是 C++ 的 模板比泛型强多了，模板有那么一点像宏（macro）。

C++ 有一个标准库，里面包含了大部分 STL 的内容，而 STL 正是利用模板实现的各种类、方法等等。可以说模板是很强的一种编程方式。

那我们是不是应该多使用模板库？那你就错了，很多游戏工作室杜绝使用模板编程，主要是因为模板本来就是一种抽象的实现，当你的模板足够复杂的时候，代码的可读性将大大降低，得不偿失，很多人说学习一门语言就是去浏览源码，我浏你个奶奶的二舅父，STL 库模板高度抽象化，何必折磨自己，最主要的是搞懂库函数的思想和用法，在正确的地方使用正确的模板才是王道。

对于 C++ 这种强类型语言，很多方法仅仅是参数类型不同，模板可以将其合为一体，这样就不必一直 copy 了。模板在日志系统和材料系统里常用，因为都是涉及各种不同的数据类型。

需要注意的是，模板并不是正真的代码，也就是说如果你不调用模板，编译器就不会去处理它，模板函数内部就算出现一些没有定义的变量，编译也不会出错，只有调用了模板，编译器才会对模板进行实例化。

## 函数样例

如果你要输出一个不确定类型变量的值，可以实现一个输出模板，如下

```c++
#include <iostream>
#include <string>

template<typename T>
void print(T value) {
	std::cout << value << std::endl;
}

int main() {
	
	print(5);
	print(5.5f);
	print("professordeng");

	std::cin.get();
}
```

## 类模板

std 命名空间下有一个叫 array 的容器类，功能和 C 的数组差不多，但是是用模板实现的，我给一个不完全的实现，如下

```c++
#include <iostream>
#include <string>

template<typename T, int N>
class Array {
private:
	T array[N];
public:
	int getSize() const { return N; }
};


int main() {
	
	Array<std::string, 50> array;
	std::cout << array.getSize() << std::endl;

	std::cin.get();
}
```



最后说一句，作为强类型语言，模板是库的灵魂，几乎所有的库都用到了模板。