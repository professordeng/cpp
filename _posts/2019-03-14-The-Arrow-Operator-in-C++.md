---
title: c++ 箭头操作符 ->
---

`->` 是在指针访问对象里面的方法或数据成员的时候用到的，因此也是一种运算符。对于变量或者引用，都是用 `.` 运算符访问对象成员，这就是区别。当然， `->` 还有一个有用的作用就是可以算出数据成员的偏移量，让我们看看下面的例子。

## 访问数据成员以及重载

我们创建一个 `ScopedPtr` 智能指针类。

```c++
#include <iostream>

class Entity  
{
	int x;
public:
	void print() const
	{
		std::cout << "hello!" << std::endl;
	}
};

class ScopedPtr   //智能指针类
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity)
	{
	}

	const Entity* operator->() const { //标识1
		return m_Obj;
	}

	Entity* operator->() {  //标识2
		return m_Obj;
	}

	~ScopedPtr() {
		delete m_Obj;
	}
};

int main() 
{
	const ScopedPtr entity1 = new Entity();
	entity1->print(); //调用 标识1

	ScopedPtr entity2 = new Entity();
	entity2->print();  //调用标识2

	std::cin.get();
}
```

我们如果不重载 `->` 标识符，将得不到私有成员的函数，除非另外写一个函数来调用成员的函数，但是这样代码可读性太差了，因此这就是箭头符的有用之处之一。

## 计算数据成员偏移地址

在结构体中，定义的顺序不同，其布局自然不同，因此有时候我们需要知道变量的偏移位置，这时候 `->` 就派上用场了

```c++
#include <iostream>
#include <string>

struct Vector3
{
	float x, y, z;
};

int main() {
	int offest = (int)&((Vector3*)nullptr)->y;
	std::cout << offest << std::endl;

	std::cin.get();
}
```

输出是 4，也就是说 y 的偏移地址是 4。如果 y 和 z 的定义对调，结果将是 8。

可能当你看到  `(int)&((Vector3*)nullptr)` 这段句子一愣一愣的，但是其实可以当做是各种显示转换的过程。

1. `nullptr`

   就是 0 的宏定义。

2. `(Vector3*)nullptr`

   将 `nullptr` 强制转换为 `Vector3` 类型。这时候该类型指针指向 0。

3. `((Vector3*)nullptr)->y`

   得到 `Vector*` 类型中的 y 变量。

4. `&((Vector3*)nullptr)->y`

   得到变量地址。

5.  `(int)&((Vector3*)nullptr)->y`

   将地址强制转换为 一个整数。

你可以将 `nullptr` 替换为 4，结果相应 +4。