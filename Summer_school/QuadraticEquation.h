#pragma once
#include <cassert>
#include <cmath>
#include <stdio.h>

/// <summary>
/// Class of quadratic equation
/// </summary>
class QuadraticEquation {
public:
    ~QuadraticEquation();

    QuadraticEquation();
    QuadraticEquation(double, double, double);
    
    int InputParams();
    void OutputRoots();
    int getRoots(double*, double*);

    bool is_equal(double, double);
private:
    /// <summary>
    /// The result of solving a quadratic equation with an infinite number of roots.
    /// </summary>
    const int INF_SOLVE_ = -1;
    /// <summary>
    /// 
    /// </summary>
    const int CODE_ERROR_ = -9;
    /// <summary>
    /// Comparison error double.
    /// </summary>
    const double EPSILON_ = 1e-5;

    /// <summary>
    /// Variables of coeficent of equation
    /// </summary>
    double a_;
    double b_;
    double c_;

    int SolveEquation_(double*, double*);
};

