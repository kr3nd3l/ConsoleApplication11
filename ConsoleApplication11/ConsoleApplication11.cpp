#include <iostream>

int reverseNumber(int num, int reversed = 0) {
   
    if (num == 0) {
        return reversed;
    }

    
    reversed = reversed * 10 + num % 10;

    
    return reverseNumber(num / 10, reversed);
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
}