# how cpp works

C++ 从代码到可执行文件需要经过那些过程，下面以`hello.cpp`为例。

```c++
#include <iostream>

int main()
{
	std::cout << "Hello World!" << std::endl;
	std::cin.get();
}
```

1. 预处理（Preprocessing）

   由预处理器完成，将源文件处理为预处理文件。其实就是将代码整合一下，将需要的头文件引入到源文件中，hello.c 预处理后也有上百条代码，因此我将输出流定向到hello.i文件中。

   ```c++
   g++ -E hello.cpp > hello.i  //生成预处理后的.i文件
   ```

2. 编译（Compilation）

   对 C++ 的语句进行翻译并优化成汇编指令，这是最核心的部分。在源文件中使用的函数和变量如果不声明的话编译将会出错。

   ```c++
   g++ -S hello.i 			//生成汇编.s文件
   ```

3. 汇编（Assembly）

   将汇编指令翻译为机器指令。

   ```c++
   g++  -c  hello.s            //生成二进制.o文件
   ```

4. 链接（Linking）

   我们可能有多个对象文件，链接器的作用就是将多个对象文件链接成一个可执行文件。

   ```c++
   g++ hello.o  -o  hello  	  //生成二进制.out可执行文件 
   ```




## 参考文献

- [How C++ Works](https://www.youtube.com/watch?v=SfGuIVzE_Os&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=5)