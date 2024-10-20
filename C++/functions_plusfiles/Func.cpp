#include "Func.hpp"
#include <cmath>
namespace lol
{
    int cout(int x)
    {
        int sum = 0;
        int a;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
    bool isPrime(int x)
{
    if (x < 2)
        return false;
    for (int d = 2; d <= sqrt(x); d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}
}