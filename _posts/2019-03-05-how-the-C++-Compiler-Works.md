# how the C++ Compiler Works

C++ 从文本文件到可执行文件需要两个最主要的过程，分别是编译和链接，那编译器是如何工作的呢，中间要经过哪些步骤？



首先会进行预处理操作，那什么是预处理操作呢。

```c++
#include <iostream>
#define INTEGER int
#if 1
Log();
#endif
```

如上，这些 `#` 开头的语句都是预处理命令，预处理操作就是处理这些语句的。预处理语句的功能正如其名字。include 是将文本文件的内容全部拷贝过来，define 是将所有 INTEGER 替换成 int ，也就是简单的替换功能，if 语句是真的话将包含的内容保留下来。

 