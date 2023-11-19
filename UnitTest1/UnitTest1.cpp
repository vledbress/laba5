#include "pch.h"
#include "CppUnitTest.h"
#include "D:\учеба\uchc++\oipz3\oipz2\oipz3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(check_valid_params_get_minus5_5_1_4_and_exceptionnotthrown)
		{
			double x = -5;
			double b = 5;
			double h = 1;
			int n = 4;
			try {
				check_valid_params(x, b, h, n);
				Assert::IsTrue(true);
			}
			catch(...) {
				Assert::IsTrue(false);
			}
		}
		TEST_METHOD(check_valid_params_get_5_minus5_1_4_and_exceptionnotthrown)
		{
			double x = 5;
			double b = -5;
			double h = 1;
			int n = 4;
			try {
				check_valid_params(x, b, h, n);
				Assert::IsTrue(false);
			}
			catch (...) {
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(calculate_get_minus1_4_and_12_return)
		{
			double x = -1;
			int n = 4;
			double exceptedy = 12;
			double real = calculate(x, n);
			Assert::AreEqual(exceptedy,real);
		}
		TEST_METHOD(calculate_get_minus2_4_and_12_return)
		{
			double x = -2;
			int n = 4;
			double exceptedy = 12;
			double real = calculate(x, n);
			Assert::AreEqual(exceptedy, real);
		}
		TEST_METHOD(WRONGTEST)
		{
			double x = -2;
			int n = 4;
			double exceptedy = -12;
			double real = calculate(x, n);
			Assert::AreEqual(exceptedy, real);
		}
	};
}
//testedFunction_functionArguments_expectedResult.