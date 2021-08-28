#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <assert.h>
#include "Functions_for_sqare.h"
#include "Functions_for_test.h"

enum MODES {
    TEST = 1,
    RUN  = 2
};

int main(void) {
    setlocale(LC_ALL, "Rus");

    double a = NAN, b = NAN, c = NAN; //a, b, c - коэффициенты уравнения.
    int mode = 0;

    double x1 = NAN;
    double x2 = NAN;

    int n_ans = 0;

    printf("Введите в каком режиме вы хотите запусть программу.\n");
    printf("Если вы хотите включить режим тестирования, введите 1.\n");
    printf("Если вы хотите запустить режим решения квадратки, введите 2.\n");

    while (scanf("%d", &mode) != 1 || mode != TEST && mode != RUN) {
        printf("Неверный ввод, попробуйте еще!\n");
        fflush(stdin);
    }

    assert(mode == RUN || mode == TEST);   //!

    switch (mode) {
        case RUN:
            work_with_human(a, b, c, x1, x2, n_ans);
            break;

        default:
            test(a, b, c, x1, x2, n_ans);
            break;
    }
    return 0;
}



