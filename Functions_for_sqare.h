#include <stdio.h>
#include <locale.h>
#include <math.h>


const double ERROR = 1e-6;

/**
    \brief Функция check_equality проверяет совпадение 2 чисел с заданной точностью.
    check_equality принимает 2 числа и сравнивает их.
    Если числа отличаются менее чем на глобальную переменную ERROR, функция возвращает 1, в противном случае - 0.
 */
int check_equality(double x, double true_x) {  // Проверяет совпадение 2 чисел с заданной точностью
    if (fabs(x - true_x) <= ERROR) {
        return 1;
    } else {
        return 0;
    }
}


/**
    \brief Функция line решает линейное уравнение.
    line принимает коэффициенты линейного уравнения и адрес переменной.
    Функция записывает ответ в x1, и возвращает число корней.
 */
int line(double b, double c, double* x1) // Решает линейную функцию
{
        /*Линейное уравнение !!!!!1 1 20!!!!*/
    if (! check_equality(b, 0)) {
        *x1 = -c / b;
        return 1;
        /*Все 0*/
    } else if (check_equality(b, 0) && check_equality(c, 0)) {
        *x1 = INFINITY;
        return INFINITY;
    /*Невозможное уравнение*/
    } else {
        return 0;
    }
}


/**
    \brief Функция square решает квадратное уравнение.
    line принимает коэффициенты квадратного уравнения и адреса переменных.
    Функция записывает ответы в x1 и x2, и возвращает число корней.
 */
int square(double a, double b, double c, double* x1, double* x2)  // Решает квадрат
{
    double D2 = 0, D = 0; // D2 - дискриминант в квадрате, D - дискриминант

    D2 = b * b - 4 * a * c;

    if (check_equality(D2, 0)) { /*ERROR модуль, константа, 2 функции */
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b + D) / (2 * a);
        return 2;
    /*Дискриминант равен 0*/
    } else if (D2 > 0) {
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b - D) / (2 * a);
        return 2;
     /*Нет решений*/
     } else {
        return 0;
    }
}


/**
    \brief Функция check_line_or_square проверяет линейная функция или квадратная.
    check_line_or_square принимает коэффициенты квадратного уравнения и адреса переменных.
    Функция записывает ответы в x1 и x2, и возвращает число корней.
 */
int check_line_or_square(double a, double b, double c, double* x1, double* x2) { // Проверяет линейная функция или квадрат
    if (check_equality(a, 0)){
        return line(b, c, x1);
    } else {
        return square(a, b, c, x1, x2);
    }
}

