# the NEW keyword in c++

`new` 的主要目的就是在堆里明确地分配内存。 看下面例子

```c++
int* p = new int;
```

当执行到关键字 `new` 的时候，会发生 3 个步骤

1. 调用名为 `operator new` 的标准库函数，向操作系统申请足够大的原始的未类型化的连续的内存，以保存指定类型的一个对象。
2. 运行该类型的一个构造函数去实例化对象。
3. 返回指向新分配的对象首地址的指针。

使用 `delete` 表达式时，分为两个步骤

1. 调用对象的析构函数
2. 调用名为 `operator delete` 的标准库函数释放该对象所用的内存。

`operator new`和 `operator delete` 函数有两个重载版本。

| new                              | delete                            |
| -------------------------------- | --------------------------------- |
| `void * operator new (size_t);`  | `void operator delete(void *);`   |
| `void * operator new[](size_t);` | `void operator delete[](void *);` |

因为有时候我们会在堆里面分配数组，就需要 `[]` 重载，如下

```c++
int* p = new int[10];
delete[] p;
```

## malloc 和 free

在 C 中也有分配堆内存和销毁堆内存的函数，分别是 `malloc` 和 `free` 。

```c++
int* p = (int*)malloc(sizeof(int[10]));
free(p);
```

C 语言是面向过程编程的，因此没有类，也就不需要构造函数，所以 `malloc` 和 `new` 的区别就是 `malloc` 没有调用构造函数这一功能。同样对比于 `delete` ，`free` 函数也就没有调用析构函数这个功能了。因此

1. C++ 分配堆内存用 `new`，不用 `malloc`。
2. C++ 销毁堆内存用 `delete` ，不用 `free` 。
3. 如果分配的内存是数组，用 `new[]` ，销毁时用 `delete[]`