# how strings work in c++

在 C 语言风格中，有两种办法存储字符串

1. 将多个字符存到字符数组里，编译器会自动在最后补 `\0` 。

2. 存储字符串常量，例如

   ```c++
   const char* name = "professordeng"
   ```

字符串常量不能修改，就不能进行符号处理，字符数组可以，但是方法都得自己实现。

为了提高开发的效率，也为了不让程序员这么快秃头，大师们开发了一个 string 类供我们 C++ 程序员使用。

## string 类

1. 数据成员

   ```c++
   union _Bxty
       {   // storage for small buffer or pointer to larger one
       _Elem _Buf[_BUF_SIZE];
       _Elem *_Ptr;
       } _Bx; 
   size_type _Mysize;  // current length of string
   size_type _Myres;   // current storage reserved for string
   ```

   string 对象占用了 28 bits 的空间在栈区，如果字符串超过 16 bits，将在堆里面开辟空间进行存储。如果每次超过容量大小，string 会自动扩容，扩充为原来的 3/2，实际上就是重新申请更大的空间，将数据拷贝过去，清除旧空间。

2. string 常用函数

## string 优化

