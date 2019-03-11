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



