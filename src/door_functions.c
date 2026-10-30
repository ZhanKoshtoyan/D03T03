#include <math.h>
#include <stdio.h>

#define M_PI 3.14159265358979323846

double agnesi(double x);
double bernoulli(double x, int *defined);
double hyperbola(double x, int *defined);

int main(void) {
    int steps = 42;
    double start = -M_PI;
    double end = M_PI;
    double step = (end - start) / (steps - 1);

    for (int i = 0; i < steps; i++) {
        double x = start + i * step;

        // Считаем Верзьеру Аньези (определена всегда)
        double y_agnesi = agnesi(x);

        // Считаем Лемнискату Бернулли
        int bernoulli_defined = 1;
        double y_bernoulli = bernoulli(x, &bernoulli_defined);

        // Считаем квадратичную гиперболу
        int hyperbola_defined = 1;
        double y_hyperbola = hyperbola(x, &hyperbola_defined);

        // Вывод абсциссы
        printf("%.7f | %.7f | ", x, y_agnesi);

        // Вывод Лемнискаты Бернулли
        if (bernoulli_defined) {
            printf("%.7f | ", y_bernoulli);
        } else {
            printf("- | ");
        }

        // Вывод квадратичной гиперболы
        if (hyperbola_defined) {
            printf("%.7f", y_hyperbola);
        } else {
            printf("-");
        }

        if (i < steps - 1) {
            printf("\n");
        }
    }

    return 0;
}

double agnesi(double x) { return 1.0 / (1.0 + x * x); }

double bernoulli(double x, int *defined) {
    double radical = sqrt(1.0 + 4.0 * x * x) - x * x - 1.0;
    if (radical < 0.0) {
        *defined = 0;
        return 0.0;
    }
    return sqrt(radical);
}

double hyperbola(double x, int *defined) {
    // Проверяем близость к нулю для double, сравнивая с 1e-9
    if (fabs(x) < 1e-9) {
        *defined = 0;
        return 0.0;
    }
    return 1.0 / (x * x);
}
