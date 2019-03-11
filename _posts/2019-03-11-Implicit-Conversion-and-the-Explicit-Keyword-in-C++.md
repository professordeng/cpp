# Implicit Conversion and the Explicit Keyword in C++

基本数据类型的显式和隐式转换相信大家都基本会了，我们看一些劲爆的。

```c++
#include <iostream>
#include <string>

class Entity
{
public:
	int age;
	std::string name;

	Entity(int age)
		: age(age), name("unknow"){}
	Entity(const std::string& name)
		: age(-1), name(name){}
	
};

int main() 
{
	Entity e1 = 22;
	Entity e2 = (std::string)"professordeng";
	std::cout << e1.age << std::endl;
	std::cout << e2.name << std::endl;
	
	std::cin.get();
}
```

运行上面程序你会发现，成功了，这就是构造函数的神奇之处。类构造函数会自动匹配对应参数进行构造，也就是存在隐式转换。那么如果为了安全考虑我们可以利用 `explicit` 修饰构造函数。如下

```c++
#include <iostream>
#include <string>

class Entity
{
public:
	int age;
	std::string name;

	explicit Entity(int age)
		: age(age), name("unknow"){}
	explicit Entity(const std::string& name)
		: age(-1), name(name){}
	
};

int main() 
{
	Entity e1(22);
	Entity e2("professordeng");
	std::cout << e1.age << std::endl;
	std::cout << e2.name << std::endl;
	
	std::cin.get();
}
```

这样就只能使用常规方法实例化对象了。当然传参的时候也可能出现隐式转换。如下

```c++
#include <iostream>
#include <string>

class Entity
{
public:
	int age;
	std::string name;

	Entity(int age)
		: age(age), name("unknow"){}
	Entity(const std::string& name)
		: age(-1), name(name){}
	
};

void PrintEntity(const Entity& entity) {
	//printing
}

int main() 
{
	PrintEntity(22);
	
	std::cin.get();
}
```

代码成功将整数转换为 Entity 对象。

相对而言，我们很少涉及到这些东西，但是还是有必要了解这些东西，谁知道会出什么 bug 呢。