#include <stdio.h>

int fibonacci(int n);

int main(void) {
    int input_number;
    char end_character = '\0';

    // 1. Проверка на корректность ввода
    if (scanf("%d%c", &input_number, &end_character) != 2 ||
        (end_character != '\n' && end_character != ' ' && end_character != '\t')) {
        printf("n/a");
        return 0;
    }

    printf("%d", fibonacci(input_number));

    return 0;
}

// Рекурсивная функция для поиска n-го числа Фибоначчи
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
