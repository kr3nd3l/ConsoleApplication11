#include <iostream>
#include <vector>

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
std::pair<int, int> recursiveSearch(const std::vector<std::vector<int>>& matrix, int target, int row, int col) {
    // Проверка границ
    if (row >= matrix.size()) {
        return { -1, -1 }; // Элемент не найден
    }
    if (col >= matrix[row].size()) {
        return recursiveSearch(matrix, target, row + 1, 0); // Переход на следующую строку
    }

    // Проверка текущего элемента
    if (matrix[row][col] == target) {
        return { row, col }; // Элемент найден
    }

    // Рекурсивный вызов для следующего элемента
    return recursiveSearch(matrix, target, row, col + 1);
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
    std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
    };

    int target = 5; // Число для поиска
    auto result = recursiveSearch(matrix, target, 0, 0);

    if (result.first != -1) {
        std::cout << "Элемент найден на индексе: (" << result.first << ", " << result.second << ")n";
    }
    else {
        std::cout << "Элемент не найден.n";
    }

    return 0;
}

