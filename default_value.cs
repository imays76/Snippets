void foo(int a = 0, int b = 1)
{
...
}

foo(_, _); // 실제로는 foo(0,1)이 됨
