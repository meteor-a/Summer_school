#include "Summer_school.h"

/*! \mainpage SolveEquation
 * This project was created to automate the solution of the quadratic equation
 * in the framework of the MIPT summer school (1 course). The program is designed 
 * to find valid roots.
 */

/*!
    * Solving a quadratic equation
*/
int main() {
    double a = 0;
    double b = 0;
    double c = 0;

    InputParams(&a, &b, &c);

    double x1 = 0;
    double x2 = 0;
    int nRoots = SolveEquation(a, b, c, &x1, &x2);

    OutputRoots(nRoots, x1, x2);
    return 1;
}

/**
    * Function for checking equality of variables of double types.
    * \return true - if the numbers are equal
    * \return false - if the numbers are not equal
*/
bool is_equal(double x /*!< - First number*/, 
              double y /*!< - Second number */) {

    return fabs(x - y) < EPSILON_;
}

/*!
    * Function for solving a quadratic equation. If one root, it store result in both pointers.
    * \return Number of roots
*/
int SolveEquation(double a /*!< - The highest coefficient */,
    double b               /*!< - The x coefficient*/,
    double c               /*!< - Free coefficent*/,
    double* x1             /*!< - Pointer for storing the 1st root */, 
    double* x2             /*!< - Pointer for storing the 2nd root */) {

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (is_equal(a, 0)) {
        if (is_equal(b, 0)) {
            return is_equal(c, 0) ? INF_SOLVE_ : 0;
        }
        else { // if b != 0
            *x1 = -c / b;
            return 1;
        }
    }
    else { // if a != 0 
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
            double sqrt_discr = sqrt(discr);
            *x1 = (-b + sqrt_discr) / (2 * a);
            *x2 = (-b - sqrt_discr) / (2 * a);
            return 2;
        }
    }
}

/*!
    * Parameter input function for quadratic equation
    * \return 1 - if all is ok.
*/
int InputParams(double* a /*!< - Pointer to the highest coefficient */,
                double* b /*!< - Pointer to the x coefficient */,
                double* c /*!< - Poiner to free coefficient */) {

    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    int nInput_a = 0;
    int nInput_b = 0;
    int nInput_c = 0;

    bool res = false;
    do {
        printf("Example of entering an equation -5x^2 + 4*x - 3\n"
               "a: %lg\n"
               "b: %lg\n"
               "c: %i\n\n", -5.0, 3.25, -4);
        
        printf("a: ");
        nInput_a = scanf("%lg", a);
        
        printf("b: ");
        nInput_b = scanf("%lg", b);
        
        printf("c: ");
        nInput_c = scanf("%lg", c);
        
        res = nInput_a != 1 && nInput_b != 1 && nInput_c != 1;
        if (res) {
            printf("Something wrong in input. Check input params.\n");
        }
    } while (res);

    return 1;
}

/*!
    * Function for outputting the results of solving a quadratic equation
    * \return
*/
void OutputRoots(int nRoots/*!< - Number of roots */,
                 double x1/*!< - First root */,
                 double x2/*!< - Second root */) {

    switch (nRoots) {
    case 0:
        printf("No Roots!\n");
        break;
    case 1:
        printf("1 Root\n" 
               "%lg\n", x1);
        break;
    case 2:
        printf("2 Roots\n" 
               "%lg\n" 
               "%lg\n", x1, x2);
        break;
    case INF_SOLVE_:
        printf("Any Roots!\n");
        break;
    default:
        printf("Error in number of roots.\n");
        break;
    }

    return;
}
