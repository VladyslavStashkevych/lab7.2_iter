#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2_iter/lab7.2_iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:
		TEST_METHOD(TestMethod1) {
			int arr[] = { 1,5,8,2,4 },
				index = IndexMax(arr, 5);
			Assert::AreEqual(2, index);
		}
	};
}
