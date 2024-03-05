#include "pch.h"
#include "CppUnitTest.h"
#include <stack>
#include "../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTest
{
	TEST_CLASS(StackTest)
	{
	public:
		TEST_METHOD(PushPopTest)
		{
			Stack myStack;
			myStack.push(5);
			Assert::AreEqual(5, myStack.top());
			myStack.pop();
			Assert::IsTrue(myStack.isEmpty());
		}

		TEST_METHOD(TopTest)
		{
			Stack myStack;
			myStack.push(10);
			Assert::AreEqual(10, myStack.top());
			myStack.push(20);
			Assert::AreEqual(20, myStack.top());
		}

		TEST_METHOD(IsEmptyTest)
		{
			Stack myStack;
			Assert::IsTrue(myStack.isEmpty());
			myStack.push(5);
			Assert::IsFalse(myStack.isEmpty());
			myStack.pop();
			Assert::IsTrue(myStack.isEmpty());
		}

		TEST_METHOD(CopyConstructorTest)
		{
			Stack myStack;
			myStack.push(5);
			myStack.push(10);
			myStack.push(15);

			Stack copyStack(myStack);
			Assert::AreEqual(myStack.top(), copyStack.top());
			myStack.pop();
			copyStack.pop();
			Assert::AreEqual(myStack.top(), copyStack.top());
		}
		TEST_METHOD(ExceptionTest)
		{
			Stack myStack;
			Assert::ExpectException<std::runtime_error>([&] { myStack.top(); });
			Assert::ExpectException<std::runtime_error>([&] { myStack.pop(); });
		}
		TEST_METHOD(CompareStacks)
		{
			Stack myStack;
			std::stack<int> stlStack;

			myStack.push(5);
			stlStack.push(5);
			Assert::AreEqual(stlStack.top(), myStack.top());

			myStack.push(10);
			stlStack.push(10);
			Assert::AreEqual(stlStack.top(), myStack.top());

			myStack.pop();
			stlStack.pop();
			Assert::AreEqual(stlStack.top(), myStack.top());

			myStack.pop();
			stlStack.pop();
			Assert::IsTrue(myStack.isEmpty());
			Assert::IsTrue(stlStack.empty());
		}
	};
}