# smart pointers in c++

Java 和 C++ 的一个很大的不同之处就是 Java 有垃圾回收机制。但是 C++ 如果想利用 new 在堆里分配内存，那么就需要自己手动清除堆内存。所以 C++ 实现了智能指针的功能，通过使用智能指针也能在堆里面分配内存，并且不需要我们 `delete` ，只要达到某些条件，智能指针会自动回收堆内存，这也是为什么 C++ 难学，因为什么都需要自己动手嘛 。

智能指针涉及内存，因此调用智能指针需要引入 `#include <memory>` 。

1. `std::unique_ptr` 

   这是唯一指针（字面意思），只要是该指针分配的内存，就会和该指针共存亡。也就是说，当我们执行到指针范围外的代码时，唯一指针就会自杀了，顺便将它分配的内存清掉。

   `uniques_str` 禁用了 `=` 操作符，也就是说，它指向的内存空间不共享的，这样它清除内存的时候就不会发生野指针的情况。

   ```c++
   #include <iostream>
   #include <memory>
   
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
   
   int main() 
   {
   	{
   		std::unique_ptr<Entity> e = std::make_unique<Entity>();
   	}  //跳出这里，指针就会自动清除堆内存
   	std::cin.get();
   }
   ```

2. `std::shared_ptr` 

   有时候，我们一块内存需要分享给几个指针，而不是像 `unique_str` 一样吃独食。这时候就需要 `shared_ptr` 指针了，这类指针内置了一个计数器，记录有多少指针一起共享这块内存，当没有指针指向这块内存时，最后一个指针在死之前会做清除工作，如下

   ```c++
   #include <iostream>
   #include <memory>
   
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
   
   int main() 
   {
   	{
   		std::shared_ptr<Entity> e0;
   		{
   			std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
   			e0 = e1;  //e0 来共用 e1 分配的内存
   		} //e1 死了，内存还在
   	} //e0 死了，顺便释放了内存
   	std::cin.get();
   }
   ```

3. `weak_str`

   `weak_str` 称为观察指针，也就是和 `shared_str` 搭配用的，但是不计入计数器，也就是说，`shared_str` 死了，就算是 `weak_str` 还指着内存，内存也会被释放的。所以才被称为弱鸡指针。

   ```c++
   #include <iostream>
   #include <memory>
   
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
   
   int main() 
   {
   	{
   		std::weak_ptr<Entity> e0;
   		{
   			std::shared_ptr<Entity> e1 = std::make_shared<Entity>();
   			e0 = e1;  //弱鸡指针 e0 来共享内存啦
   		} //e1 要死了，顺便带走了内存
   	}
   	std::cin.get();
   }
   ```

   

