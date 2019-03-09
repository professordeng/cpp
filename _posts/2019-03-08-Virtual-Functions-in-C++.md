# Virtual Functions in C++

子类可以用父类指针引用，但是父类不可以用子类指针引用。

那么有一个问题，如果父类和子类有一个函数重名了怎么办，最后运行的时候是调用哪一个函数，这时候需要用到虚函数这个概念。

```c++
#include <iostream>
#include <string>

class Entity
{
	std::string name;
public:
	virtual std::string getName() {
		return "professordeng";
	}
};

class Player : public Entity
{
public:
	std::string getName() override {
		return "david";
	}
	
};

int main()
{
	Entity* p = new Player();

	std::cout << p->getName() << std::endl;
	
	std::cin.get();
}
```

如上面的程序，如果去掉 `virtual` 和 `override` 关键字，输出的结果不会是 `david` 。

每一个函数虚函数的类都至少有一个与之对应的虚函数表，其中存放着该类所有的虚函数对应的函数指针。

虚函数重名会进行替换，该过程是由编译器完成的，因此也可以说：虚函数替换过程发生在编译时。

多重继承的子类含有每一个父类的虚函数表。

菱形继承不讨论，这玩意复杂程度大于实用价值。