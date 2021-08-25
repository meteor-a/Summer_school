#pragma once
#include <iostream>
#include <cassert>
/// <summary>
/// The result of solving a quadratic equation with an infinite number of roots.
/// </summary>
const int INF_SOLVE = -1;

const int CODE_ERROR = -9;

/// <summary>
/// Comparison error double.
/// </summary>
const double EPSILON = 1e-5;

/**
    * Function for checking equality of variables of double types.
    * \return true - if the numbers are equal
    * \return false - if the numbers are not equal
*/
bool is_equal(double x /*!< - First number*/, double y /*!< - Second number */) {
    return fabs(x - y) < EPSILON;
}

/*!
    * Function for solving a quadratic equation.
    * \return Number of roots
*/
int SolveSquare(double a /*!< -Highest degree coefficient */, double b/*!< - Coefficient at x*/,
    double c/*!< - Free member */, double* x1/*!< - Pointer for storing the 1st root */, double* x2/*!< - Pointer for storing the 2nd root */) {

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
    * Parameter input function for quadratic equation
    * \return
*/
int InputParams(double* a/*!< - Pointer to highest degree coefficient */,
    double* b/*!< - Pointer to coefficient at x*/,
    double* c/*!< - Pointer to free term pointer */) {

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
    * Function for outputting the results of solving a quadratic equation
    * \return
*/
void OutputRoots(int* nRoots/*!< - Pointer to the number of roots */,
    double* x1/*!< - Pointer to 1st root */,
    double* x2/*!< - Pointer to 2nd root */) {

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
