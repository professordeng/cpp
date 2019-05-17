---
title: c++ 拷贝函数
---

编程的时候，我们会利用一个已知的变量来初始化一个新的变量，这就叫复制。例如

```c++
int a = 1;
int b = a;
```

C++ 所有的基本类型和大多数类都有默认的复制函数，我们称之为拷贝函数。

```c++
#include <iostream>
#include <string>

class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string) {  //构造函数
 		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size + 1);
	}

	String(const String& other) //拷贝函数
		: m_Size(other.m_Size)
	{
		std::cout << "copyed String!" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	char& operator[](unsigned int index) {  //重载，返回修改地址
		return m_Buffer[index];
	}

	~String() {  //有 new 就有 delete
		delete[] m_Buffer;
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);  
    
};

//输出符重载
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string) { //一般情况下都用 & 引用提高效率
	std::cout << string << std::endl;
}

int main() 
{
	String string = "professordeng";
	String second = string;

	second[2] = 'i';

	PrintString(string);

	std::cin.get();
}
```

在这里我们试着对完整代码进行修改

1. 删掉拷贝函数

   这时候就会调用默认操作函数，只有浅拷贝，两个对象共用一个堆内存，销毁内存时会销毁两次，出错。而且你会发现，输出的是 `prifessordeng` 。

   因此，只要对象的数据成员涉及到堆内存分配，一定要重写拷贝函数。

2. 删掉 `PrintString` 函数中参数的 & 符

   这时候传参会出现一次深拷贝，在堆里分配内存是一件很浪费资源的行为，我们仅仅为了输出信息而进行深拷贝，得不偿失，因此，大多数情况，我们都用引用符修饰参数。如果你学过 JAVA 就有所体会。