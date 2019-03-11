# Member Initializer Lists in C++ (Constructor Initializer List)

每个类实例化的时候都需要有初始函数，C++ 提供了成员初始列表的方式供我们使用，而且我们也要尽可能使用该方法实例化对象，有如下几个原因

1. 代码更加简洁

   ```c++
   class Entity 
   {
   private:
   	int x, y;
   public:
   	Entity()
   		: x(1), y(2)
   	{}
   };
   ```

   这里成员初始列表的顺序和定义顺序一样，代码清晰，不需要在结构体里面写两行赋值语句。

2. 效率高

   如果你运行下面的代码，会发现 `Example` 实例化了两次，第一次是自己的初始函数，还有一次是浅拷贝函数。 

   ```c++
   #include <iostream>
   
   class Example
   {
   public:
   	Example()
   	{
   		std::cout << "Created Entity!" << std::endl;
   	}
   	Example(int x)
   	{
   		std::cout << "Created Entity with " << x << "!" << std::endl;
   	}
   };
   
   class Entity 
   {
   private:
   	Example example;
   public:
   	Entity()
   	{
   		example = Example(8);
   	}
   };
   
   int main() 
   {
   	Entity e;
   	std::cin.get();
   }
   ```

   只要稍微修改一下 `Entity` 类的构造函数，你就会发现数据成员会直接调用第二个构造函数。

   ```c++
   class Entity 
   {
   private:
   	Example example;
   public:
   	Entity()
   		: example(8)
   	{
   	}
   };
   ```

   因此，这不只是代码风格的问题，已经影响到程序性能了。

3. `const` 常量的实例化

   `const` 常量的实例化必须使用成员列表，而不能在构造函数体里面赋值。因为常量不能作为左值。

   ```c++
   class Entity 
   {
   public:
   	const int x;
   	Entity()
   		: x(8)
   	{	
   	}
   };
   
   int main() 
   {
   	Entity e;
   	std::cout << e.x << std::endl;
   
   	std::cin.get();
   }
   ```

   

