#include <stdio.h>
#include <locale.h>
#include <math.h>


const double ERROR = 1e-6;


int check_equality(double x, double true_x) {  // Проверяет совпадение 2 чисел с заданной точностью
    if (fabs(x - true_x) <= ERROR) {
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
    } else if (fabs(D2) <= ERROR) { /*ERROR модуль, константа, 2 функции */
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b + D) / (2 * a);
        return 2;
     /*Нет решений*/
     } else {
        return 0;
    }
}



int check_line_or_square(double a, double b, double c, double* x1, double* x2){ // Проверяет линейная функция или квадрат
    if (a == 0){
        return line(a, b, c, x1, x2);
    } else {
        return square(a, b, c, x1, x2);
    }
}

