﻿#include <iostream>

int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; 
    std::cout << "num fib for " << n << ": " << fibonacci(n) << std::endl;
    return 0;
}