#include <stdio.h>
#include <locale.h>
#include <math.h>


const double ERROR = 1e-6;
enum N_ANSVERS{
    ONE = 1,
    TWO = 2,
    NO_ANS = 0,
    INF = -1
};

/**
    \brief Функция check_equality проверяет совпадение 2 чисел с заданной точностью.
    check_equality принимает 2 числа и сравнивает их.
    Если числа отличаются менее чем на глобальную переменную ERROR, функция возвращает 1, в противном случае - 0.
 */
int check_equality(double x, double true_x) {  // Проверяет совпадение 2 чисел с заданной точностью
    return fabs(x - true_x) <= ERROR;    //if is not needed - сделано
}

/**
    \brief Функция line решает линейное уравнение.
    line принимает коэффициенты линейного уравнения и адрес переменной.
    Функция записывает ответ в x1, и возвращает число корней.
 */
int decide_line(double b, double c, double* x1) // Решает линейную функцию
{
    //assert()

    if (! check_equality(b, 0)) {
        *x1 = -c / b;
        return ONE;
        /*Все 0*/
    } else if (check_equality(b, 0) && check_equality(c, 0)) {
        *x1 = INFINITY;       //!
        return INF;            // enum
    /*Невозможное уравнение*/
    } else {
        return NO_ANS;
    }
}

/**
    \brief Функция square решает квадратное уравнение.
    line принимает коэффициенты квадратного уравнения и адреса переменных.
    Функция записывает ответы в x1 и x2, и возвращает число корней.
 */
int decide_square(double a, double b, double c, double* x1, double* x2)  // Решает квадрат
{
    //assert(a != 0 &&)

    double D = b * b - 4 * a * c;
    double sqrt_D = NAN;

    if (check_equality(D, 0)) { /*ERROR модуль, константа, 2 функции */
        sqrt_D = sqrt(D);                //another variable name - сделано
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b + sqrt_D) / (2 * a);
        return TWO;
    /*Дискриминант равен 0*/
    } else if (D > 0) {
        sqrt_D = sqrt(D);
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b - sqrt_D) / (2 * a);
        return TWO;
     /*Нет решений*/
     } else {
        return NO_ANS;
    }
}

/**
    \brief Функция check_line_or_square проверяет линейная функция или квадратная.
    check_line_or_square принимает коэффициенты квадратного уравнения и адреса переменных.
    Функция записывает ответы в x1 и x2, и возвращает число корней.
 */
int check_line_or_square(double a, double b, double c, double* x1, double* x2) { // Проверяет линейная функция или квадрат
    if (check_equality(a, 0)) {
        return decide_line(b, c, x1);
    }      //поменял название

    return decide_square(a, b, c, x1, x2);//поменял название
}

/**
    \brief Функция human_decide работает с человеком.
    human_decide принимает коэффициенты a, b, c, корни x1 и x2 и число решений.
    Пользователь вводит коэффициенты a, b, c, и функция возвращает число корней и печатает ответ.
 */
int work_with_human(double a, double b, double c, double x1, double x2, int n_ans) { // Человек вводит коэффициенты
    printf("Введите через пробел коэффициенты квадратного уравнения:\n");

    while (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Неверный ввод, попробуйте еще\n");
        fflush(stdin);
    }

    n_ans = check_line_or_square(a, b, c, &x1, &x2);

    switch (n_ans) {
        case NO_ANS:
            printf("Уравнение не имеет решений!");
            break;

        case ONE:
            printf("x = %lf", x1);
            break;

        case TWO:
            printf("x1 = %lf, x2 = %lf", x1, x2);
            break;

        case INF:
            printf("Решением является любое число");
            break;

        default:
            printf("Решением является любое число");
            break;
    }
}
