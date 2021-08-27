#include <stdio.h>
#include <locale.h>
#include <math.h>


const double ERROR = 1e-6;

/**
    \brief ������� check_equality ��������� ���������� 2 ����� � �������� ���������.
    check_equality ��������� 2 ����� � ���������� ��.
    ���� ����� ���������� ����� ��� �� ���������� ���������� ERROR, ������� ���������� 1, � ��������� ������ - 0.
 */
int check_equality(double x, double true_x) {  // ��������� ���������� 2 ����� � �������� ���������
    if (fabs(x - true_x) <= ERROR) {
        return 1;
    } else {
        return 0;
    }
}


/**
    \brief ������� line ������ �������� ���������.
    line ��������� ������������ ��������� ��������� � ����� ����������.
    ������� ���������� ����� � x1, � ���������� ����� ������.
 */
int line(double b, double c, double* x1) // ������ �������� �������
{
        /*�������� ��������� !!!!!1 1 20!!!!*/
    if (! check_equality(b, 0)) {
        *x1 = -c / b;
        return 1;
        /*��� 0*/
    } else if (check_equality(b, 0) && check_equality(c, 0)) {
        *x1 = INFINITY;
        return INFINITY;
    /*����������� ���������*/
    } else {
        return 0;
    }
}


/**
    \brief ������� square ������ ���������� ���������.
    line ��������� ������������ ����������� ��������� � ������ ����������.
    ������� ���������� ������ � x1 � x2, � ���������� ����� ������.
 */
int square(double a, double b, double c, double* x1, double* x2)  // ������ �������
{
    double D2 = 0, D = 0; // D2 - ������������ � ��������, D - ������������

    D2 = b * b - 4 * a * c;

    if (check_equality(D2, 0)) { /*ERROR ������, ���������, 2 ������� */
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b + D) / (2 * a);
        return 2;
    /*������������ ����� 0*/
    } else if (D2 > 0) {
        D = sqrt(D2);
        *x1 = (-b + D) / (2 * a);
        *x2 = (-b - D) / (2 * a);
        return 2;
     /*��� �������*/
     } else {
        return 0;
    }
}


/**
    \brief ������� check_line_or_square ��������� �������� ������� ��� ����������.
    check_line_or_square ��������� ������������ ����������� ��������� � ������ ����������.
    ������� ���������� ������ � x1 � x2, � ���������� ����� ������.
 */
int check_line_or_square(double a, double b, double c, double* x1, double* x2) { // ��������� �������� ������� ��� �������
    if (check_equality(a, 0)){
        return line(b, c, x1);
    } else {
        return square(a, b, c, x1, x2);
    }
}

