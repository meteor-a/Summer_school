#include "pch.h"
#include "CppUnitTest.h"
#include "../Summer_school/Summer_school.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <math.h> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		TEST_METHOD(TestInput) {
            std::ifstream file("C:\\Users\\Maxim\\source\\repos\\Summer_school\\Tests\\Tests\\DataInputTests.txt");

            if (!file.is_open()) {
                Assert::Fail();
            }
            int num_of_tests = 0;
            file >> num_of_tests;
            for (int ii = 0; ii < num_of_tests; ++ii) {
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

                int nRoots = SolveEquation(a_test, b_test, c_test, &x1, &x2);

                Assert::AreEqual(nRoots, nRoots_test);
                if (nRoots == 1) {
                    Assert::IsTrue(is_equal(x1,x1_test));
                } else if (nRoots == 2) {
                    Assert::IsTrue(is_equal(x1, x1_test));
                    Assert::IsTrue(is_equal(x2, x2_test));
                }
                else if (nRoots != 0) {
                    Assert::Fail();
                }
            }
		}
	};
}
