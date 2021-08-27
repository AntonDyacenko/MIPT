#include <stdio.h>
#include <locale.h>
#include <math.h>


const double ERROR = 1e-6;


int check_equality(double x, double true_x) {  // ��������� ���������� 2 ����� � �������� ���������
    if (fabs(x - true_x) <= ERROR) {
        return 1;
    } else {
        return 0;
    }
}


int line(double a, double b, double c, double* x1, double* x2) // ������ �������� �������
{
        /*�������� ��������� !!!!!1 1 20!!!!*/
    if (a == 0 && b != 0) {
        *x1 = -c / b;
        return 1;
        /*��� 0*/
    } else if (a == 0 && b == 0 && c == 0) {
        *x1 = INFINITY;
        *x2 = INFINITY;
        return INFINITY;
    /*����������� ���������*/
    } else {
        return 0;
    }
}



int square(double a, double b, double c, double* x1, double* x2)  // ������ �������
{
    double D2 = 0, D = 0; // D2 - ������������ � ��������, D - ������������

    D2 = b * b - 4 * a * c;

    if (D2 > 0) {
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b - D) / (2 * a);
        return 2;
    /*������������ ����� 0*/
    } else if (fabs(D2) <= ERROR) { /*ERROR ������, ���������, 2 ������� */
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b + D) / (2 * a);
        return 2;
     /*��� �������*/
     } else {
        return 0;
    }
}



int check_line_or_square(double a, double b, double c, double* x1, double* x2){ // ��������� �������� ������� ��� �������
    if (a == 0){
        return line(a, b, c, x1, x2);
    } else {
        return square(a, b, c, x1, x2);
    }
}

