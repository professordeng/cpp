# obj lifetime in c++ (Stack/Scope lifetimes)

对象的生存周期可以通过它的构造函数和析构函数调用得知。我们先构造一个实体类。

```c++
class Entity
{
public:
	Entity() {
		std::cout << "created Entity!" << std::endl;
	}
	~Entity() {
		std::cout << "destroyed Entity!" << std::endl;
	}
};
```

当主函数如下时，只要程序没有终止，就不会调用 e 的析构函数。

```c++
int main() 
{
	Entity e;
	std::cin.get();
}
```

但是我们做一些修改，添加一个 `{}` 进去，你就会发现，e 刚刚生成就被销毁了

```c++
int main() 
{
	{
		Entity e;
	}
	std::cin.get();
}
```

也就是说，栈里面的对象的生存周期取决于 `{}` 。