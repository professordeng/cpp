# references in C++

引用和指针是很相似的，也算是指针的延伸。C++ 中引用的符号是 `&`，但是要和取地址符 `&` 区分开来。  

C++ 编程语言中，默认传参是传形参的，也就是调用函数的时候并不修改真正的值，而是修改副本的值，如果想利用函数修改真正的值，可以通过指针操作内存直接修改，但是利用引用会更加简单。

值得注意的是，引用一旦赋值，就不能改变。也就是说你不能将你的别名转给别人。引用在声明的时候就应该定义。准确的说不是定义，是引用，因为引用并不占内存。

```c++
int a = 1;
int b = 2;
int& ref = a;
ref = b;
```

如上，这样运行的结果并不是将引用指向 b，而是令 `a=b`。