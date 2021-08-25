#pragma once
#include <iostream>
#include <cassert>
/// <summary>
/// ��������� ������� ����������� ��������� ��� ����������� ���������� ������.
/// </summary>
const int INF_SOLVE = -1;

const int CODE_ERROR = -9;

/// <summary>
/// ���������� ��� ��������� double.
/// </summary>
const double EPSILON = 1e-5;

/**
    * ������� ��� �������� ��������� ���������� double �����.
    * \return true - ���� ����� �����
    * \return false - ���� ����� �� �����
*/
bool is_equal(double x /*!< - ������ �����*/, double y /*!< - ������ ����� */) {
    return fabs(x - y) < EPSILON;
}

/*!
    * ������� ��� ������� ����������� ���������.
    * \return ���������� ������
*/
int SolveSquare(double a /*!< -���������� ��� ������� ������� */, double b/*!< - ���������� ��� x*/,
    double c/*!< - ��������� ���� */, double* x1/*!< - ��������� ��� �������� 1-�� ����� */, double* x2/*!< - ��������� ��� �������� 2-�� ����� */) {

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
    * ������� ����� ���������� ����������� ���������
    * \return
*/
int InputParams(double* a/*!< - ��������� �� ������� ��������� */,
    double* b/*!< - ��������� �� ���������� ��� x */,
    double* c/*!< - ��������� �� ��������� ���� */) {

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
    * ������� ������ ����������� ������� ����������� ���������
    * \return
*/
void OutputRoots(int* nRoots/*!< - ��������� �� ���������� ������ */,
    double* x1/*!< - ��������� �� 1-�� ������ */,
    double* x2/*!< - ��������� �� 2-� ������ */) {

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
