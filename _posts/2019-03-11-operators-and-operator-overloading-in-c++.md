# operators and operator overloading in c++

C++ 中的操作符的功能和函数一样，但是写起来比函数直观，处理数学操作符，我们还有`&` ， `→` ，`+=` 以及位运算符 `<<` ，以及分配内存用的 `new` 和 `delete` 操作符。

相同的符号，可以赋予不同的功能，这就是运算符重载，例如矩阵的乘法和整数的乘法是不一样的，所以矩阵的乘法需要对 `×` 进行重载。

JAVA 不允许重载，C# 运行部分符号重载，C++ 就不一样了，随你喜欢。当然这有好处也有坏处，如果代码写得不好，将会出现很多莫名其妙的 bug，这也是为什么 C++ 精通是需要成本的。

如果你想要使用重载符，那么就一定要有它的意义，如果你用逗号 `,`  来重载实现加法，那么等待你的就是裁员书了。

但是我还是喜欢 C++，因为 C++ 写的代码简洁又高效。不过 JAVA 也有一些类似的功能解决可读性问题，例如 `ToString` 方法。

## 样例

由于操作符和函数的功能一样，因此操作符的实现也和函数类似。我将定义二维向量类来实现操作符重载以及相同功能的函数实现。

```c++
#include <iostream>

struct Vector2
{
	float x, y;

	Vector2(float x = 1, float y = 1)
		: x(x), y(y){}
	Vector2 Add(const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator + (const Vector2& other) const {
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Mutiply(const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}
	Vector2 operator * (const Vector2& other) const {
		return Vector2(x * other.x, y * other.y);
	}

	bool operator == (const Vector2& other) const {
		return x == other.x && y == other.y;
	}
};

std::ostream& operator << (std::ostream& stream, const Vector2& other) {
	stream << other.x << ", " << other.y;
	return stream;
}

int main() 
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	Vector2 result1 = position.Add(speed.Mutiply(powerup));
	Vector2 result2 = position + speed * powerup;

	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;
	
	if (result1 == result2) {
		std::cout << "good" << std::endl;
	}

	std::cin.get();
}
```

该样例重载了 向量`+`  、 向量  `==` 、 向量 `*` 向量输出 `<<` 。更多的操作符都有固定的格式。



## 参考文献

- [C++ operators](https://en.cppreference.com/w/cpp/language/operators)