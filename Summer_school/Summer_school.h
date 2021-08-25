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


bool is_equal(double, double);
int SolveSquare(double, double, double, double*, double*);
int InputParams(double*, double*, double*);
void OutputRoots(int*, double*, double*);