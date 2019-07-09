---
title: 数组
---

数组逻辑上是线性表，结构如下

![array](/cpp-learning/img/array.png)

C++ 支持数组数据结构，这是最简单易懂的数据结构，详细请看 [C++数组](http://www.runoob.com/cplusplus/cpp-arrays.html)。

值得注意的是，数组一旦分配了空间，数组的大小就是固定的了。

## vector

vector 是 C++ 的一个动态数组类模板，实现了数组的基本操作。

首先，vector 内部的存储结构是数组，但是当数据量超过分配的空间时，vector 会自动扩大容量。方式是将原来数组中的数据复制到一个新的更大的数组中。另一个和 vector 互补的就是链表，链表的存储空间是碎片化的，利用指针来确定数据元之间的关系，因此扩大容量的时候比 vector 要高效。

因此，如果你使用 vector 类，那么优化的方向就是尽量减少数据的复制。为了优化该问题，我先写了个简单的节点元素结构体。如下，只有一个简单的构造函数和检测复制的拷贝函数。

```c++
struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		: x(x), y(y), z(z)
	{
	}

	Vertex(const Vertex& vertex) 
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "copied" << std::endl;
	}
};
```

1. 低级版本

   ```c++
   int main() {
   	std::vector<Vertex> vertices;
   	vertices.push_back(Vertex(1, 2, 3));
   	vertices.push_back(Vertex(4, 5, 6));
   	vertices.push_back(Vertex(7, 8, 9));
   
   	std::cin.get();
   	return 0;
   }
   ```

   运行程序，你会发现有六次拷贝操作

2. 升级版本

   也许你猜到了，也许是刚开始分配的空间太小，可以经过调试一步步发现，那如果我们一开始就分配足够的空间会怎么样，如下，利用 reserve 函数进行预分配。

   ```c++
   int main() {
   	std::vector<Vertex> vertices;
   	vertices.reserve(3);
   	vertices.push_back(Vertex(1, 2, 3));
   	vertices.push_back(Vertex(4, 5, 6));
   	vertices.push_back(Vertex(7, 8, 9));
   
   	std::cin.get();
   	return 0;
   }
   ```

   运行程序，发现只剩下3次拷贝。

3. 终极版本

   我们进行 push_back 的时候，其实是形参传递，主函数生成的 Vertex 对象并直接在 vector 内存中，该过程存在拷贝行为，为了解决问题，我们可以利用 emplace_back 操作直接将参数传递给 vector，如下

   ```c++
   int main() {
   	std::vector<Vertex> vertices;
   	vertices.reserve(3);
   	vertices.emplace_back(1, 2, 3);
   	vertices.emplace_back(4, 5, 6);
   	vertices.emplace_back(7, 8, 9);
   
   	std::cin.get();
   	return 0;
   }
   ```

   这时候，终于不存在拷贝操作了，优化成功。

## 总结

1. 数组一旦分配空间，大小就已经确定。
2. 数组的内存空间是连续的。
3. 减少拷贝是高效利用vector的关键。

## 参考文献

- [C++的vector函数详解](http://www.runoob.com/w3cnote/cpp-vector-container-analysis.html)
- [Dynamic arrays in C++ (std::vector)](https://www.youtube.com/watch?v=PocJ5jXv8No&t=600s)
- [Optimizing the usage of std::vector in C++](https://www.youtube.com/watch?v=HcESuwmlHEY)



