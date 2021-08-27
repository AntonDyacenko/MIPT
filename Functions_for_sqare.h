#include <stdio.h>
#include <locale.h>
#include <math.h>


const double ERROR = 1e-6;

int chek_NAN_INF(double x, double true_x) {    // Сравнивает NAN и INF
    if (isnan(x) && isnan(true_x) || isinf(x) && isinf(true_x)) {
        return 1;
    } else {
        return 0;
    }
}

int check_equality(double x, double true_x) {  // Проверяет совпадение 2 чисел с заданной точностью
    if (fabs(x - true_x) <= ERROR) {
        return 1;
    } else {
        return 0;
    }
    }

int check_all_numbers(double x1, double true_x1, double x2, double true_x2) {   // Проверяет равенство полученных ответов и образца
    if (check_equality(x1, true_x1) && check_equality(x2, true_x2) || check_equality(x1, true_x2) && check_equality(x2, true_x1)
    || check_equality(x1, true_x1) && chek_NAN_INF(x2, true_x2) || chek_NAN_INF(x1, true_x2) && check_equality(x2, true_x1)
    || chek_NAN_INF(x1, true_x1) && chek_NAN_INF(x2, true_x2)) {
        return 1;
    } else {
        return 0;
    }
}

int check_n_roots(int n_roots, int true_n_roots) { // Проверяет кол-во корней
    if (chek_NAN_INF(n_roots, true_n_roots) || check_equality(n_roots, true_n_roots)) {
        return 1;
    } else {
        return 0;
    }
}

int line(double a, double b, double c, double* x1, double* x2) // Решает линейную функцию
{
        /*Линейное уравнение !!!!!1 1 20!!!!*/
    if (a == 0 && b != 0) {
        *x1 = -c / b;
        return 1;
        /*Все 0*/
    } else if (a == 0 && b == 0 && c == 0) {
        *x1 = INFINITY;
        *x2 = INFINITY;
        return INFINITY;
    /*Невозможное уравнение*/
    } else {
        return 0;
    }
}



int square(double a, double b, double c, double* x1, double* x2)  // Решает квадрат
{
    double D2 = 0, D = 0; // D2 - дискриминант в квадрате, D - дискриминант

    D2 = b * b - 4 * a * c;

    if (D2 > 0) {
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b - D) / (2 * a);
        return 2;
    /*Дискриминант равен 0*/
    } else if (fabs(D2) <= 1e-6) { /*1e-6 модуль, константа, 2 функции */
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b + D) / (2 * a);
        return 2;
     /*Нет решений*/
     } else {
        return 0;
    }
}



int check(double a, double b, double c, double* x1, double* x2){ // Проверяет линейная функция или квадрат
    if (a == 0){
        return line(a, b, c, x1, x2);
    } else {
        return square(a, b, c, x1, x2);
    }
}

