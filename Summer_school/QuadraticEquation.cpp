#include "QuadraticEquation.h"

/**
    * Destructor
*/
QuadraticEquation::~QuadraticEquation() {   
}

/**
    * Constructor default(all params inizialize 0)
*/
QuadraticEquation::QuadraticEquation() {
    a_ = 0;
    b_ = 0;
    c_ = 0;
}

/**
    * Constructor initializing variables as coefficients of an equation
*/
QuadraticEquation::QuadraticEquation(double a/*!< -Highest degree coefficient */, 
    double b/*!< - Coefficient at x*/, 
    double c/*!< - Free member */) {

    assert(isfinite(a) && isfinite(b) && isfinite(c));
    a_ = a;
    b_ = b;
    c_ = c;
}

/**
    * Function for checking equality of variables of double types.
    * \return true - if the numbers are equal
    * \return false - if the numbers are not equal
*/
bool QuadraticEquation::is_equal(double x /*!< - First number*/, double y /*!< - Second number */) {
    return fabs(x - y) < EPSILON_;
}

/*!
    * Function for solving a quadratic equation.
    * \return Number of roots
*/
int QuadraticEquation::SolveEquation_(double* x1/*!< - Pointer for storing the 1st root */, double* x2/*!< - Pointer for storing the 2nd root */) {

    assert(x1 != nullptr && x2 != nullptr);
    assert(isfinite(a_) && isfinite(b_) && isfinite(c_));

    if (is_equal(a_, 0)) {
        if (is_equal(b_, 0)) {
            if (is_equal(c_, 0)) {
                return INF_SOLVE_;
            }
            return 0;
        }
        else { // if b != 0
            *x1 = -c_ / b_;
            return 1;
        }
    }
    else { // if a == 0 
        double discr = b_ * b_ - 4 * a_ * c_;
        if (discr < 0) {
            return 0;
        }
        else if (discr == 0) {
            *x1 = (-b_) / (2 * a_);
            *x2 = *x1;
            return 1;
        }
        else { // if discr > 0
            double sqrt_discr = sqrt(discr);
            *x1 = (-b_ + sqrt_discr) / (2 * a_);
            *x2 = (-b_ - sqrt_discr) / (2 * a_);
            return 2;
        }

    }
}

/*!
    * Parameter input function for quadratic equation
    * \return 1 - if all is ok.
    * \return -9 - if something wrong.
*/
int QuadraticEquation::InputParams() {
    printf("Example of entering an equation -5x^2 + 4*x - 3 \na: %lg \nb: %lg \nc: %i\n \n", -5.0, 3.25, -4);
    printf("a: ");
    int nInput_a = scanf("%lg", &a_);
    printf("b: ");
    int nInput_b = scanf("%lg", &b_);
    printf("c: ");
    int nInput_c = scanf("%lg", &c_);
    if (nInput_a != 1 && nInput_b != 1 && nInput_c != 1) {
        printf("Something wrong in input/ Check input params");
        return CODE_ERROR_;
    }

    return 1;
}

/*!
    * Function for outputting the results of solving a quadratic equation
    * \return
*/
void QuadraticEquation::OutputRoots() {

    double x1 = 0;
    double x2 = 0;
    int nRoots = SolveEquation_(&x1, &x2);

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
    return;
}

/*!
    * Function for getting the results of solving a quadratic equation
    * \return Number of roots.
*/
int QuadraticEquation::getRoots(double* x1 /*!< - Pointer for storing the 1st root */, 
    double* x2/*!< - Pointer for storing the 2nd root */) {

    assert(x1 != nullptr && x2 != nullptr);
    return SolveEquation_(x1, x2);
}
