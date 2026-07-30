#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128]={0};
    int cached=0;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) { if (i < 0 || i >= 128) {
            throw std::out_of_range("Index out of range");}
if (i < cached) {
            return cache[i];// 返回缓存值
        }
 cache[0] = 0;// F(0)
        if (i > 0) {
            cache[1] = 1;// F(1)
        }
        for (int j=2; j<=i; ++j) {
            cache[j] = cache[j - 1] + cache[j- 2];
        }
         cached = i + 1;                          
        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
