#include "Summer_school.h"

/*!
    * Solving a quadratic equation
*/
int main() {
    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    
    int res_input = InputParams(&a, &b, &c);
    if (res_input == CODE_ERROR) {
        return CODE_ERROR;
    }

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    OutputRoots(&nRoots, &x1, &x2);

    return 0;
}