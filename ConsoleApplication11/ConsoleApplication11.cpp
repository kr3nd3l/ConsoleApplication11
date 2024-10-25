#include <iostream>

int reverseNumber(int num, int reversed = 0) {
   
    if (num == 0) {
        return reversed;
    }

    
    reversed = reversed * 10 + num % 10;

    
    return reverseNumber(num / 10, reversed);
}
int ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    }
    else if (m == 1) {
        return n + 2;
    }
    else if (m == 2) {
        return 2 * n + 3;
    }
    else if (m == 3) {
        return (1 << (n + 3)) - 3; // 2^(n+3) - 3
    }
    else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    int number;

    std::cout << "enter number: ";
    std::cin >> number;

    
    bool isNegative = number < 0;
    if (isNegative) {
        number = -number;
    }

    int reversedNumber = reverseNumber(number);

   
    if (isNegative) {
        reversedNumber = -reversedNumber;
    }

    std::cout << "reverse number: " << reversedNumber << std::endl;

    return 0;

    int m = 3; // Пример: значение m
    int n = 4; // Пример: значение n
    std::cout << "A(" << m << ", " << n << ") = " << ackermann(m, n) << std::endl;
    return 0;
}

