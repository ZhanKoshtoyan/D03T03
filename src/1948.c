#include <math.h>
#include <stdio.h>

int is_divisible(int dividend, int divisor);
int get_max_prime_divisor(int number);

int main(void) {
    int input_number;
    char end_character = '\0';

    // 1. Проверка на корректность ввода
    if (scanf("%d%c", &input_number, &end_character) != 2 ||
        (end_character != '\n' && end_character != ' ' && end_character != '\t')) {
        printf("n/a");
        return 0;
    }

    // 2. Избавляемся от знака минус
    if (input_number < 0) {
        input_number = -input_number;
    }

    // 3. Исключаем 0 и 1, так как у них нет простых делителей
    if (input_number == 0 || input_number == 1) {
        printf("n/a");
        return 0;
    }

    // 4. Вызываем функцию подсчета значения
    int result = get_max_prime_divisor(input_number);

    // 5. Выводим результат без переноса строки на конце
    if (result == -1) {
        printf("n/a");
    } else {
        printf("%d", result);
    }

    return 0;
}

// Проверяет, делится ли число нацело (1 = делится, 0 = есть остаток)
int is_divisible(int dividend, int divisor) {
    while (dividend >= divisor) {
        dividend = dividend - divisor;
    }

    int check_result = 0;
    if (dividend == 0) {
        check_result = 1;
    }

    return check_result;
}

// Ищет наибольший простой делитель числа
int get_max_prime_divisor(int number) {
    int max_divisor = -1;

    // Идем по всем потенциальным делителям числа
    for (int current_divisor = 2; current_divisor <= number; current_divisor++) {
        // Если число делится на текущий делитель
        if (is_divisible(number, current_divisor)) {
            int is_prime = 1;
            // Оптимизация: проверяем простоту делителя только до его квадратного
            // корня
            int limit = (int)sqrt(current_divisor);

            for (int check_factor = 2; check_factor <= limit; check_factor++) {
                if (is_divisible(current_divisor, check_factor)) {
                    is_prime = 0;
                    break;
                }
            }

            // Если делитель оказался простым, запоминаем его как максимальный
            if (is_prime == 1) {
                max_divisor = current_divisor;
            }
        }
    }

    return max_divisor;
}
