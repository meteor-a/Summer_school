#pragma once
#include <iostream>
#include <cassert>
/// <summary>
/// Результат решения квадратного уравнения при бесконечном количестве корней.
/// </summary>
const int INF_SOLVE = -1;

const int CODE_ERROR = -9;

/// <summary>
/// Погрешност при сравнении double.
/// </summary>
const double EPSILON = 1e-5;

/**
    * Функция для проверки равенства переменных double типов.
    * \return true - если числа равны
    * \return false - если числа не равны
*/
bool is_equal(double x /*!< - Первое число*/, double y /*!< - Второе число */) {
    return fabs(x - y) < EPSILON;
}

/*!
    * Функция для решения квадратного уравнения.
    * \return Количество корней
*/
int SolveSquare(double a /*!< -Коэффицент при старшей степени */, double b/*!< - Коэффицент при x*/,
    double c/*!< - Свободный член */, double* x1/*!< - Указатель для хранения 1-го корня */, double* x2/*!< - Указатель для хранения 2-го корня */) {

    assert(x1 != nullptr && x2 != nullptr);
    assert(isfinite(a) && isfinite(b) && isfinite(c));

    if (is_equal(a, 0)) {
        if (is_equal(b, 0)) {
            if (is_equal(c, 0)) {
                return INF_SOLVE;
            }
            return 0;
        }
        else { // if b != 0
            *x1 = -c / b;
            return 1;
        }
    }
    else { // if a == 0 
        double discr = b * b - 4 * a * c;
        if (discr < 0) {
            return 0;
        }
        else if (discr == 0) {
            *x1 = (-b) / (2 * a);
            *x2 = *x1;
            return 1;
        }
        else { // if discr > 0
            *x1 = (-b + sqrt(discr)) / (2 * a);
            *x2 = (-b - sqrt(discr)) / (2 * a);
            return 2;
        }

    }
}

/*!
    * Функция ввода параметров квадратного уравнения
    * \return
*/
int InputParams(double* a/*!< - Указатель на старший кэффицент */,
    double* b/*!< - Указатель на коэффицент при x */,
    double* c/*!< - Указатель на свободный член */) {

    assert(a != nullptr && b != nullptr && c != nullptr);

    printf("Example of entering an equation -5x^2 + 4*x - 3 \na: %lg \nb: %lg \nc: %i\n \n", -5.0, 3.25, -4);
    printf("a: ");
    short int nInput_a = scanf("%lg", a);
    printf("b: ");
    short int nInput_b = scanf("%lg", b);
    printf("c: ");
    short int nInput_c = scanf("%lg", c);
    if (nInput_a != 1 && nInput_b != 1 && nInput_c != 1) {
        printf("Something wrong in input/ Chtck input params");
        return CODE_ERROR;
    }

    return 1;
}

/*!
    * Функция вывода пезультатов решения квадратного уравнения
    * \return
*/
void OutputRoots(int* nRoots/*!< - Указатель на количество корней */,
    double* x1/*!< - Указатель на 1-ый корень */,
    double* x2/*!< - Указатель на 2-й корень */) {

    assert(nRoots != nullptr && x1 != nullptr && x2 != nullptr);

    if (*nRoots == 0) {
        printf("No Roots!");
    }
    else if (*nRoots == 1) {
        printf("1 Root \n %lg", *x1);
    }
    else if (*nRoots == 2) {
        printf("2 Roots \n %lg \n %lg", *x1, *x2);
    }
    else {
        printf("Any Roots!");
    }
    return;
}
