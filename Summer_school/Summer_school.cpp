#include <iostream>
#include <cassert>
#include <limits>

/// <summary>
/// Результат решения квадратного уравнения при бесконечном количестве корней.
/// </summary>
const short int INF_SOLVE = -1;

/// <summary>
/// Погрешност при сравнении double.
/// </summary>
const double EPSILON = 1e-5;

/**
    * Функция для проверки равенства переменных double типов.
    * Входные данные: double, double.
    * Выходные данные: bool.
    * true, если равны; false, если не равны. С учетом EPSILON
*/

bool is_equal(double x, double y) {    
    return std::fabs(x - y) < EPSILON;
}

/*!
    * Функция для решения квадратного уравнения.
    * Входные данные: double, double, double, double *, double *
    * Выходные данные: bool(true, если равны; false, если не равны)
    * На вход подаются коэффиценты квадратного уравения и указатели на переменные для хранения корней. Функция возвращает количество корней уравнения.
*/
short int SolveSquare(double a, double b, double c, double *x1, double *x2) {
    assert(x1 != nullptr && x2 != nullptr);
    assert(isfinite(a) && isfinite(b) && isfinite(c));

    if (is_equal(a, 0)) {
        if (is_equal(b, 0)) {
            if (is_equal(c, 0)) {
                return INF_SOLVE;
            }
            return 0;
        }
        else {
            *x1 = -c / b;
            return 1;
        }
    } else { // 
        double discr = b * b - 4 * a * c;
        if (discr < 0) {
            return 0;
        }
        else if (discr == 0) {
            *x1 = (-b) / (2 * a);
            *x2 = *x1;
            return 1;
        } else {
            *x1 = (-b + sqrt(discr)) / (2 * a);
            *x2 = (-b - sqrt(discr)) / (2 * a);
            return 2;
        }

    }
}

int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    
    
    printf("Example of entering an equation -5x^2 + 4*x - 3 \na: %lg \nb: %lg \nc: %i\n \n", -5.0, 3.25, -4);
    printf("a: ");
    short int nInput_a = scanf("%lg",&a);
    printf("b: ");
    short int nInput_b = scanf("%lg", &b);
    printf("c: ");
    short int nInput_c = scanf("%lg", &c);
    if (nInput_a != 1 && nInput_b != 1 && nInput_c != 1) {

        exit(1);
    }

    short int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if (nRoots == 0) {
        printf("No Roots!");
    }
    else if (nRoots == 1) {
        printf("1 Root \n %lg", x1);
    }
    else if (nRoots == 2) {
        printf("2 Roots \n %lg \n %lg", x1, x2);
    }
    else {
        printf("Any Roots!");
    }

    return 0;
}