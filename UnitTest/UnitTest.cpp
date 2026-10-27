// Unit-тест для ітераційної версії (проєкт pr6_2_iter)
// Тестується функція IndexOfMin() – повертає індекс найменшого непарного елемента
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6_2_iter/pr6_2_iter.cpp"     // шлях за потреби змінити

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62Iter
{
	TEST_CLASS(UnitTest62Iter)
	{
	public:

		// непарні 7, 9, 5 – найменше 5 з індексом 4
		TEST_METHOD(MixedElements)
		{
			int a[] = { 4, 7, 2, 9, 5 };
			Assert::AreEqual(4, IndexOfMin(a, 5));
		}

		// непарних немає – очікуємо -1
		TEST_METHOD(NoOddElements)
		{
			int a[] = { 2, 4, 6, 8 };
			Assert::AreEqual(-1, IndexOfMin(a, 4));
		}

		// від'ємні непарні: найменше -7 з індексом 1
		TEST_METHOD(NegativeOddElements)
		{
			int a[] = { 3, -7, -1, 8 };
			Assert::AreEqual(1, IndexOfMin(a, 4));
		}

		// найменше повторюється – індекс першого
		TEST_METHOD(DuplicateMinimum)
		{
			int a[] = { 5, 3, 8, 3 };
			Assert::AreEqual(1, IndexOfMin(a, 4));
		}

		// усі елементи непарні
		TEST_METHOD(AllOdd)
		{
			int a[] = { 9, 7, 11, 1, 5 };
			Assert::AreEqual(3, IndexOfMin(a, 5));
		}

		// найменше непарне першим
		TEST_METHOD(MinOddIsFirst)
		{
			int a[] = { -3, 4, 5, 6, 7 };
			Assert::AreEqual(0, IndexOfMin(a, 5));
		}

		// найменше непарне останнім
		TEST_METHOD(MinOddIsLast)
		{
			int a[] = { 8, 5, 10, 3 };
			Assert::AreEqual(3, IndexOfMin(a, 4));
		}

		// масив з одного елемента
		TEST_METHOD(SingleElement)
		{
			int odd[] = { 9 };
			int even[] = { 8 };
			Assert::AreEqual(0, IndexOfMin(odd, 1));
			Assert::AreEqual(-1, IndexOfMin(even, 1));
		}

		// менші за непарні парні числа не впливають на результат
		TEST_METHOD(SmallerEvenIgnored)
		{
			int a[] = { -10, 0, 3, -4, 1 };
			Assert::AreEqual(4, IndexOfMin(a, 5));
		}
	};
}