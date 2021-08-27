#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <assert.h>

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
        chek_NAN_INF(x1, true_x1)   && chek_NAN_INF(x2, true_x2)) {
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


