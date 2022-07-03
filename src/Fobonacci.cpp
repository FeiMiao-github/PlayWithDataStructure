#include <iostream>
#include <cassert>

typedef int cache[2];

void FobonacciSub(int m, cache ret)
{
    if (m-- > 0)
    {
        int tmp = ret[0] + ret[1];
        ret[0] = ret[1];
        ret[1] = tmp;
        std::cout << tmp << '\n';
        FobonacciSub(m, ret);
    }
}

void FobonacciSub(int m)
{
    assert(m < 2);

    if (--m >= 0)
    {
        FobonacciSub(m);
        std::cout << m << '\n';
    }
}

void Fobonacci(int m)
{
    if (m < 2)
    {
        FobonacciSub(m);
    }
    else
    {
        cache tmp = {0, 1};
        FobonacciSub(m, tmp);
    }
}

int main()
{
    Fobonacci(500);
    return 0;
}