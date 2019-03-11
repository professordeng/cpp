# How to create or instantiate objects in C++

类的实例化有两种方法，分别是直接定义和使用 new 关键字定义。

1. 直接定义

   如果你直接定义一个对象，对象会被实例化到栈中，当代码运行到这个对象的范围之外后，该对象的内存空间就会被操作系统自动释放。

   ```c++
   #include <iostream>
   #include <string>
   
   class Entity 
   {
   public:
   	std::string name;
   	Entity() 
   		: name("unknow"){}
   	Entity(const std::string& name)
   		: name(name){}
   };
   
   
   int main() 
   {
   	{
   		Entity e("professordeng");
   	}
   	std::cout << e.name << std::endl;
   	std::cin.get();
   }
   ```

   该程序中，对象 e 被中括号括起来了，也就是它的范围就是在这个中括号内，只要 PC 指针跳出该中括号，里面的内存空间就会被清除，也就是栈空间的 pop 操作，导致输出 `e.name` 的语句会提示出现错误。

2. new 堆分配

   另一种实例化对象的方法就是利用 new 创建对象，这时候操作系统会在堆里面提供内存，在 JAVA 中，所有对象都是在堆里面分配内存，但是 JAVA 有垃圾回收算法，而 C++ 需要程序员手动 delete 。也就是说，分配在堆里面的对象，和范围是无关的，操作系统不会帮我们回收，将上述主函数稍微修改一下

   ```c++
   int main() 
   {
   	Entity* p;
   	{
   		p = new Entity("professordeng");
   	}
   	std::cout << p->name << std::endl;
   	std::cin.get();
   }
   ```

   这时候，编译器就不会报错了。

## 用栈还是用堆

1. 当你想要你的对象的生存时间超过所在的范围生存时间，用堆。
2. 当需要很大一块空间来存储你的对象的时候，用堆。

除了以上两种情况，一律用栈分配给实例化的对象，这样可以提高程序的效率，而且栈里的变量会由操作系统自动回收，何乐而不为。