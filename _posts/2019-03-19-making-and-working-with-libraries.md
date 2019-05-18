---
title: c++ 制作静态链接库
---

链接库让我们开发变得模块化，变得有层次化，学会在 VS 2019 下建立静态库，有助于合作开发项目。

大学学计算机，很多课程开发的时候需要几个同学进行合作，那么对项目的分工就比较重要，利用静态库的思想和 `github`  提供的仓库，可以完美分配任务。

我们以一个游戏项目为例子，建立一个自己的静态链接库。

1. 建立项目 

   创建一个名字为 Game 的空项目。进入项目后，右击右边的 "解决方案 Game"，添加一个名字为 Engine 的项目。 

   右击 Engine 项目，在 general 的默认选项中选择配置类型为 `静态库` ，其默认类型为应用。然后保证 `配置` 为 所有配置，`平台` 为所有平台即可。

2. 编写 Game

   显示所有文件，然后右击新建文件夹 `src`，在该文件夹下新建 `Application.cpp`

   ```c++
   #include "Engine.h"
   
   int main() {
   	engine::printMessage(); 
   }
   ```

   这里需要用到 Engine 静态链接库，首先预处理的 include 应该包含 `Engine.h` ，在属性的 general 中的 include 添加 `$(SolutionDir)Engine/src` 也就是相对路径。这里保证了编译不出错。

   但是链接的时候就需要用到编译好的静态链接库，这时候右击 Game 选择添加然后点击引用，可以看到  Engine，点击选中确定即可。这时候 VS 会自动查看链接库。也就是说，如果 Engine 项目发生了改变，那么 Game 也会进行重新编译。

3. 编写 Engine

   显示所有文件，然后右击新建文件夹 `src`，在该文件夹下新建 `Engine.cpp` 和 `Engine.h` 头文件
   
   编写 `Engine.h` 如下
   
   ```c++
   #pragma once
   
   namespace engine {
   	void printMessage();
   }
   ```
   
   编写 `Engine.cpp` 如下
   
   ```c++
   #include "Engine.h"
   
   #include <iostream>
   
   namespace engine{
   
   	void printMessage() {
   		std::cout << "hello world!" << std::endl;
   	}
   }
   ```
   
   静态库创建完毕
   
4. 在 `Game` 项目中编译运行，此时如何 `Game` 依赖的 `Engine` 库没有编译，会先编译库再进行链接。使用静态链接库生成的可执行文件是不需要任何依赖的，也就是说执行点击 `exe` 就可以运行，这和动态库不同。

