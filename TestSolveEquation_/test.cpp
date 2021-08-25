#include "pch.h"
#include "../Summer_school/Summer_school.h"
#include <fstream>
#include <cstdlib>

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
    std::ifstream file("D:\\vs_project\\Summer_school\\TestSolveEquation_\\Tests\\DataInputTests.txt");
    if (!file.is_open()) {
        int tt = 0;
    }

    double a_test = 0;
    double b_test = 0;
    double c_test = 0;
    int nRoots_test = 0;
    double x1_test = 0;
    double x2_test = 0;

    file >> a_test >> b_test >> c_test >> nRoots_test;
    if (nRoots_test == 1) {
        file >> x1_test;
    }
    else if (nRoots_test == 2) {
        file >> x1_test;
        file >> x2_test;
    }

    double x1 = 0;
    double x2 = 0;
    int nRoots = SolveSquare(a_test, b_test, c_test, &x1, &x2);
    
    EXPECT_EQ(nRoots, nRoots_test);
    EXPECT_DOUBLE_EQ(x1_test, x1);
    EXPECT_DOUBLE_EQ(x2, x2_test);
}