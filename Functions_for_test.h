#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <assert.h>

/**
    \brief Функция chek_NAN_INF сравнивает NAN и INF.
    chek_NAN_INF принимает 2 числа.
    Если передано 2 NAN или 2 INF Функция возвращает 1, если нет, то 0.
 */
int chek_NAN_INF(double x, double true_x) {    // Сравнивает NAN и INF
    if (isnan(x) && isnan(true_x) || isinf(x) && isinf(true_x)) {
        return 1;
    } else {
        return 0;
    }
}

/**
    \brief Функция check_all_numbers Проверяет равенство полученных ответов и образца.
    chek_NAN_INF принимает 2 полученных ответа и 2 ответа-образца.
    Если они равны, возвращается 1, если нет - 0.
 */
int check_all_numbers(double x1, double true_x1, double x2, double true_x2) {   // Проверяет равенство полученных ответов и образца
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
    \brief Функция check_n_ans Проверяет кол-во корней.
    chek_NAN_INF принимает число полученных корней и число корней-образцов.
    Если они равны, возвращается 1, если нет - 0.
 */
int check_n_ans(int n_ans, int true_n_ans) { // Проверяет кол-во корней
    if (chek_NAN_INF(n_ans, true_n_ans) || check_equality(n_ans, true_n_ans)) {
        return 1;
    } else {
        return 0;
    }
}


