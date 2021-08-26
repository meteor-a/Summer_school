#pragma once
#include <math.h>
#include <cassert>
#include <stdio.h>

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

bool is_equal(double, double);
int SolveEquation(double, double, double, double*, double*);
int InputParams(double*, double*, double*);
void OutputRoots(int, double, double);
