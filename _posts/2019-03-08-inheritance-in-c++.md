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

## 继承前缀

我们发现继承的时候总是需要前面加一个 public，因为默认是 protected 继承。如下图

| 父类中的访问属性 | 继承方式                 | 子类中的访问属性 |
| ---------------- | ------------------------ | ---------------- |
| private          | public/protected/private | 不允许访问       |
| public           | public                   | public           |
| public           | protected                | protected        |
| public           | private                  | private          |
| protected        | public                   | protected        |
| protected        | protected                | protected        |
| protected        | private                  | private          |

```c++
#include <iostream>
#include <string>

class Entity
{
public:
	int x, y;
};

class Player : Entity
{
public:
	int getX() {
		return x;
	}
	Player() {
		x = 1;
	}
};

int main()
{
	Player p;
	// p.x = 2;  这行出错
	std::cout << p.getX() << std::endl;
	
	std::cin.get();
}
```

