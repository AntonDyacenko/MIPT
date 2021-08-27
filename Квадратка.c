#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <assert.h>
#include "Functions_for_sqare.h"
#include "Functions_for_test.h"

int const N_tests = 11;


struct UnitTest {
    double a;
    double b;
    double c;
    double true_x1;
    double true_x2;
    int true_n_ans;
};


/**
    \brief ������� human_decide �������� � ���������.
    human_decide ��������� ������������ a, b, c, ����� x1 � x2 � ����� �������.
    ������������ ������ ������������ a, b, c, � ������� ���������� ����� ������ � �������� �����.
 */
int human_decide(double a, double b, double c, double x1, double x2, int n_ans) { // ������� ������ ������������
    printf("������� ����� ������ ������������ ����������� ���������:\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("�������� ����!!!");
        return 0;
    }

    n_ans = check_line_or_square(a, b, c, &x1, &x2);

    switch (n_ans) {
        case 0:
            printf("��������� �� ����� �������!");
            break;

        case 1:
            printf("x = %lf", x1);
            break;

        case 2:
            printf("x1 = %lf, x2 = %lf", x1, x2);
            break;
        default:
            printf("�������� �������� ����� �����");
            break;
    }
}


/**
    \brief ������� test ��������� ���������.
    test ��������� ������������ a, b, c, ����� x1 � x2 � ����� �������.
 */
int test(double a, double b, double c, double x1, double x2, int n_ans) {  // ��������� ��������� ����
    int n_mistakes = 0;
    struct UnitTest tests[N_tests] = {
        {2, 2, 2, NAN, NAN, 0},
        {0, 0, 0, INFINITY, NAN, INFINITY},
        {0, 2, 3, -1.5, NAN, 1},
        {3, 7, -6, 0.666666666666666, -3, 2},
        {-1, 7, 8, -1, 8, 2},
        {4, 4, 1, -0.5, -0.5, 2},
        {2, 1, 1, NAN, NAN, 0},
        {-1, 2, 8, -2, 4, 2},
        {9, -6, 1, 0.3333333333, 0.3333333333, 2},
        {1, 3, 2, -2, -1, 2},
        {1, -5, 6, 2, 3, 2}
    };

    for (int i = 0; i < N_tests; i ++) {
        x1 = NAN;
        x2 = NAN;
        n_ans = check_line_or_square(tests[i].a, tests[i].b,tests[i].c, &x1, &x2);
        if (check_all_numbers(x1, tests[i].true_x1, x2, tests[i].true_x2) && check_n_ans(n_ans, tests[i].true_n_ans)){
                printf("%d - \tOk\n", i + 1);
        } else {
            n_mistakes += 1;
            printf("%d - \t�� ������!!!!", i + 1);
            printf("\t�����: (x1=%lf, x2=%lf, ������: %d), �������: (x1=%lf, x2=%lf, ������: %d)\n", x1, x2, n_ans, tests[i].true_x1, tests[i].true_x2, tests[i].true_n_ans);
        }
    }
    printf("\n����������� ������ - %d\n", n_mistakes);
}



int main(void)
{
    setlocale(LC_ALL, "Rus"); /*������������� ������� ����*/

    double a = NAN, b = NAN, c = NAN; //a, b, c - ������������ ���������.
    int mode = 0;

    double x1 = NAN;
    double x2 = NAN;

    int n_ans = 0; //

    printf("������� � ����� ������ �� ������ ������� ���������.\n");
    printf("���� �� ������ �������� ����� ������������, ������� 1.\n");
    printf("���� �� ������ ��������� ����� ������� ���������, ������� 2.\n");
    scanf("%d", &mode);

    assert(mode == 1 || mode == 2);

    switch (mode) {
        case 2:
            human_decide(a, b, c, x1, x2, n_ans);
            break;

        case 1:
            test(a, b, c, x1, x2, n_ans);
            break;
    }
    return 0;
}



