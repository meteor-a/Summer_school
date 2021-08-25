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


bool is_equal(double, double);
int SolveSquare(double, double, double, double*, double*);
int InputParams(double*, double*, double*);
void OutputRoots(int*, double*, double*);