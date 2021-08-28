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
    \brief ������� check_equality ��������� ���������� 2 ����� � �������� ���������.
    check_equality ��������� 2 ����� � ���������� ��.
    ���� ����� ���������� ����� ��� �� ���������� ���������� ERROR, ������� ���������� 1, � ��������� ������ - 0.
 */
int check_equality(double x, double true_x) {  // ��������� ���������� 2 ����� � �������� ���������
    return fabs(x - true_x) <= ERROR;    //if is not needed - �������
}

/**
    \brief ������� line ������ �������� ���������.
    line ��������� ������������ ��������� ��������� � ����� ����������.
    ������� ���������� ����� � x1, � ���������� ����� ������.
 */
int decide_line(double b, double c, double* x1) // ������ �������� �������
{
    //assert()

    if (! check_equality(b, 0)) {
        *x1 = -c / b;
        return ONE;
        /*��� 0*/
    } else if (check_equality(b, 0) && check_equality(c, 0)) {
        *x1 = INFINITY;       //!
        return INF;            // enum
    /*����������� ���������*/
    } else {
        return NO_ANS;
    }
}

/**
    \brief ������� square ������ ���������� ���������.
    line ��������� ������������ ����������� ��������� � ������ ����������.
    ������� ���������� ������ � x1 � x2, � ���������� ����� ������.
 */
int decide_square(double a, double b, double c, double* x1, double* x2)  // ������ �������
{
    //assert(a != 0 &&)

    double D = b * b - 4 * a * c;
    double sqrt_D = NAN;

    if (check_equality(D, 0)) { /*ERROR ������, ���������, 2 ������� */
        sqrt_D = sqrt(D);                //another variable name - �������
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b + sqrt_D) / (2 * a);
        return TWO;
    /*������������ ����� 0*/
    } else if (D > 0) {
        sqrt_D = sqrt(D);
        *x1 = (-b + sqrt_D) / (2 * a);
        *x2 = (-b - sqrt_D) / (2 * a);
        return TWO;
     /*��� �������*/
     } else {
        return NO_ANS;
    }
}

/**
    \brief ������� check_line_or_square ��������� �������� ������� ��� ����������.
    check_line_or_square ��������� ������������ ����������� ��������� � ������ ����������.
    ������� ���������� ������ � x1 � x2, � ���������� ����� ������.
 */
int check_line_or_square(double a, double b, double c, double* x1, double* x2) { // ��������� �������� ������� ��� �������
    if (check_equality(a, 0)) {
        return decide_line(b, c, x1);
    }      //������� ��������

    return decide_square(a, b, c, x1, x2);//������� ��������
}

/**
    \brief ������� human_decide �������� � ���������.
    human_decide ��������� ������������ a, b, c, ����� x1 � x2 � ����� �������.
    ������������ ������ ������������ a, b, c, � ������� ���������� ����� ������ � �������� �����.
 */
int work_with_human(double a, double b, double c, double x1, double x2, int n_ans) { // ������� ������ ������������
    printf("������� ����� ������ ������������ ����������� ���������:\n");

    while (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("�������� ����, ���������� ���\n");
        fflush(stdin);
    }

    n_ans = check_line_or_square(a, b, c, &x1, &x2);

    switch (n_ans) {
        case NO_ANS:
            printf("��������� �� ����� �������!");
            break;

        case ONE:
            printf("x = %lf", x1);
            break;

        case TWO:
            printf("x1 = %lf, x2 = %lf", x1, x2);
            break;

        case INF:
            printf("�������� �������� ����� �����");
            break;

        default:
            printf("�������� �������� ����� �����");
            break;
    }
}
