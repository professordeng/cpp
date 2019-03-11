# ternary operation in c++ (conditional assignment)

让我们看下面一个例子

```c++
int main() 
{
	int score = 80;
	std::string level;
	if (score > 59) {
		level = "pass";
	}
	else
	{
		level = "fail";
	}
	std::cin.get();
}
```

给成绩评级的时候，简单的判断却需要这么多行代码实现，那么有没有更换的解决方法呢？

使用三目运算符可以很简单地实现同样的效果，如下

```c++
int main() 
{
	int score = 80;
	std::string level = score > 59 ? "pass" : "fail";

	std::cout << level << std::endl;
	std::cin.get();
}
```

一句话就解决了。当然，三目运算符还可以嵌套使用，因为也有可能你的评级有三层。

```c++
int main() 
{
	int score = 80;
	std::string level = score > 59 ? score < 80 ? "pass" : "good" : "fail";

	std::cout << level << std::endl;
	std::cin.get();
}
```

此时输出结果就是 good。

## 效率比较

如果没有编译器优化的话，理论上三目运算符会快一些，但是发布的程序都是用 release 模式下优化后的，所以没必要纠结效率问题，三目运算符的简洁性更加有价值。