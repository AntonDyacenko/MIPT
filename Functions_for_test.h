#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <assert.h>

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
    \brief ������� chek_NAN_INF ���������� NAN � INF.
    chek_NAN_INF ��������� 2 �����.
    ���� �������� 2 NAN ��� 2 INF ������� ���������� 1, ���� ���, �� 0.
 */
int chek_NAN_INF(double x, double true_x) {    // ���������� NAN � INF
    if (isnan(x) && isnan(true_x) || isinf(x) && isinf(true_x)) {
        return 1;
    } else {
        return 0;
    }
}

/**
    \brief ������� check_all_numbers ��������� ��������� ���������� ������� � �������.
    chek_NAN_INF ��������� 2 ���������� ������ � 2 ������-�������.
    ���� ��� �����, ������������ 1, ���� ��� - 0.
 */
int check_all_numbers(double x1, double true_x1, double x2, double true_x2) {   // ��������� ��������� ���������� ������� � �������
    if (check_equality(x1, true_x1) && check_equality(x2, true_x2) ||
        check_equality(x1, true_x2) && check_equality(x2, true_x1) ||
        check_equality(x1, true_x1) && chek_NAN_INF(x2, true_x2)   ||
        chek_NAN_INF(x1, true_x2)   && check_equality(x2, true_x1) ||
        chek_NAN_INF(x1, true_x1)   && chek_NAN_INF(x2, true_x2))  {
            return 1;
    } else {
        return 0;
    }
}


/**
    \brief ������� check_n_ans ��������� ���-�� ������.
    chek_NAN_INF ��������� ����� ���������� ������ � ����� ������-��������.
    ���� ��� �����, ������������ 1, ���� ��� - 0.
 */
int check_n_ans(int n_ans, int true_n_ans) { // ��������� ���-�� ������
    if (chek_NAN_INF(n_ans, true_n_ans) || check_equality(n_ans, true_n_ans)) {
        return 1;
    } else {
        return 0;
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
        {0, 0, 0, INFINITY, NAN, INF},
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
        if (check_all_numbers(x1, tests[i].true_x1, x2, tests[i].true_x2) &&
            check_n_ans(n_ans, tests[i].true_n_ans)) {
                printf("%d - \tOk\n", i + 1);
        } else {
            n_mistakes += 1;
            printf("%d - \t�� ������!!!!", i + 1);
            printf("\t�����: (x1=%lf, x2=%lf, ������: %d), �������: (x1=%lf, x2=%lf, ������: %d)\n",
                   x1, x2, n_ans, tests[i].true_x1, tests[i].true_x2, tests[i].true_n_ans);
        }
    }
    printf("\n����������� ������ - %d\n", n_mistakes);
}



