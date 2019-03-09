# inheritance in c++

继承是 C++ 一个重要的特性。

我们允许有基础类，其他类可以继承这个类的共有属性。

继承的出现，避免了代码的复制。

```c++
#include <iostream>

class Entity
{
public:
	float x, y;
};

class Player : public Entity
{
public:
	char* name;
};

int main()
{
	std::cout << sizeof(Entity) << std::endl;
	std::cout << sizeof(Player) << std::endl;

	std::cin.get();
}
```

可以测试一下上面的代码，Player 类继承了 Entity 所有的东西，自然内存是12 bytes。