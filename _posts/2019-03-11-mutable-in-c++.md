# mutable in c++

`mutable` 是可变的意思，为了突破 `const` 的封锁。也就是说，不管函数有没有 `const` 的限制，`mutable` 变量都可以在里面赋值。

```c++
class Entity{
  int x;
  mutable int time;
  void printX() const
  {
      cout << x << endl;
      time ++;
  }
};
```

由于 `printX` 有 `const` 修饰，普通变量无法在里面进行修改，但是如果用 `mutable` 修饰，我们就可以对 `time` 进行修改。

## lambda 表达式

C++ 11 引入了 Lambda 表达式，利用 Lambda 表达式，可以方便的定义和创建匿名函数。

### 完整的声明格式

```c++
[capture list] (params list) mutable exception-> return type { function body }
```

各项具体含义如下

- `capture list` : 捕获外部变量列表
- `params list` : 形参列表
- `mutable` : 用来说明是否可以修改捕获的变量
- `exception` : 异常设定
- `return type` : 返回类型
- `function body` : 函数体

此外，我们还可以省略其中的某些成分来声明 “不完整” 的 Lambda 表达式，常见的有以下几种

| 序号 | 格式                                                        |
| ---- | ----------------------------------------------------------- |
| 1    | [capture list] (params list) -> return type {function body} |
| 2    | [capture list] (params list) {function body}                |
| 3    | [capture list] {function body}                              |

格式 1 表明了 `const` 类型的表达式，这种类型的表达式不能修改捕获列表中的值。

格式 2 省略了返回值类型，但编译器可以根据以下规则推断出Lambda表达式的返回类型 

- 如果function body中存在return语句，则该Lambda表达式的返回类型由return语句的返回类型确定
- 如果function body中没有return语句，则返回值为void类型。

格式 3 中省略了参数列表，类似普通函数中的无参函数。

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return  a < b;
}

int main()
{
	vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
	vector<int> lbvec(myvec);

	sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
	cout << "predicate function:" << endl;
	for (int it : myvec)
		cout << it << ' ';
	cout << endl;

	sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式
	cout << "lambda expression:" << endl;
	for (int it : lbvec)
		cout << it << ' ';

	cin.get();
}
```

在 C++ 11 之前，我们使用 `STL` 的 `sort` 函数，需要提供一个谓词函数。如果使用 C++ 11 的Lambda 表达式，我们只需要传入一个匿名函数即可，方便简洁，而且代码的可读性也比旧式的做法好多了。

### 捕获外部变量

Lambda 表达式可以使用其可见范围内的外部变量，但必须明确声明（明确声明哪些外部变量可以被该 Lambda 表达式使用）。Lambda 表达式通过在最前面的方括号 `[]` 来明确指明其内部可以访问的外部变量，这一过程也称过 Lambda 表达式“捕获”了外部变量。

```c++
int main()
{
	int a = 123;
	auto f = [a] { cout << a << endl; };
	f(); // 输出：123

	//或通过“函数体”后面的‘()’传入参数
	[](int a) {cout << a << endl; }(123);
}
```

上面这个例子先声明了一个整型变量 a ，然后再创建 Lambda 表达式，该表达式 “捕获” 了 a 变量，这样在 Lambda 表达式函数体中就可以获得该变量的值。

类似参数传递方式（值传递、引入传递、指针传递），在 Lambda 表达式中，外部变量的捕获方式也有值捕获、引用捕获、隐式捕获。

1. 值捕获

   值捕获和参数传递中的值传递类似，被捕获的变量的值在 Lambda 表达式创建时通过值拷贝的方式传入，因此随后对该变量的修改不会影响影响 Lambda 表达式中的值。

   ```c++
   int main()
   {
   	int a = 123;
   	auto f = [a] { cout << a << endl; };
   	a = 321;
   	f(); // 输出：123
   }
   ```

   这里需要注意的是，如果以传值方式捕获外部变量，则在 Lambda 表达式函数体中不能修改该外部变量的值（你可以试着在函数体里修改 a 的值）。

2. 引用捕获

   使用引用捕获一个外部变量，只需要在捕获列表变量前面加上一个引用说明符 `&`。

   ```c++
   int main()
   {
       int a = 123;
       auto f = [&a] { cout << a << endl; }; 
       a = 321;
       f(); // 输出：321
   }
   ```

   从示例中可以看出，引用捕获的变量使用的实际上就是该引用所绑定的对象。

3. 隐式捕获

   上面的值捕获和引用捕获都需要我们在捕获列表中显示列出 Lambda 表达式中使用的外部变量。除此之外，我们还可以让编译器根据函数体中的代码来推断需要捕获哪些变量，这种方式称之为隐式捕获。隐式捕获有两种方式，分别是 `[=]` 和 `[&]` 。`[=]` 表示以值捕获的方式捕获外部变量，`[&]` 表示以引用捕获的方式捕获外部变量。

   ```c++
   int main()
   {
       int a = 123;
       auto f = [=] { cout << a << endl; };    // 值捕获
       f(); // 输出：123
   }
   ```

   ```c++
   int main()
   {
       int a = 123;
       auto f = [&] { cout << a << endl; };    // 引用捕获
       a = 321;
       f(); // 输出：321
   }
   ```

4. 混合方式

   上面的例子，要么是值捕获，要么是引用捕获，Lambda 表达式还支持混合的方式捕获外部变量，这种方式主要是以上几种捕获方式的组合使用。

   | 捕获形式  | 说明                                                         |
   | --------- | ------------------------------------------------------------ |
   | []        | 不捕获任何外部变量                                           |
   | [type, …] | 默认以值得形式捕获指定的多个外部变量（用逗号分隔），如果引用捕获，需要显示声明（使用 & 说明符） |
   | [this]    | 以值的形式捕获this指针                                       |
   | [=]       | 以值的形式捕获所有外部变量                                   |
   | [&]       | 以引用形式捕获所有外部变量                                   |
   | [=, &x]   | 变量 x 以引用形式捕获，其余变量以传值形式捕获                |
   | [&, x]    | 变量 x 以值的形式捕获，其余变量以引用形式捕获                |

### 修改捕获变量

前面我们提到过，在 Lambda 表达式中，如果以传值方式捕获外部变量，则函数体中不能修改该外部变量，否则会引发编译错误。这就需要使用 `mutable` 关键字，该关键字用以说明表达式体内的代码可以修改值捕获的变量，示例：

```c++
int main()
{
	int a = 123;
	auto f = [a]() mutable { cout << ++a; }; // 不会报错
	cout << a << endl; // 输出：123
	f(); // 输出：124
}
```

### Lambda表达式的参数

Lambda表达式的参数和普通函数的参数类似，但是 Lambda 表达式中传递参数还有一些限制

1. 参数列表中不能有默认参数
2. 不支持可变参数
3. 所有参数必须有参数名

```c++
int main()
{
	int m = [](int x) { return [](int y) { return y * 2; }(x)+6; }(5);
	cout << "m:" << m << endl;           //m为16

	cout << "n:" << [](int x, int y) { return x + y; }(5, 4) << endl;   //输出n:9
}
```



## 参考文献

- [C++ 11 Lambda 表达式](https://www.cnblogs.com/DswCnblog/p/5629165.html)

