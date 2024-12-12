#include "CppUnitTest.h"
#include <functional>
#include "../List/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{
	TEST_CLASS(ListUnitTest)
	{
	public:
		TEST_METHOD(DeleteListSize0)
		{
			List<int> list;
		}
		TEST_METHOD(DeleteListSize1ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 2);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize2ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 3);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(DeleteListSize5ThenNoMemoryLeak)
		{
			auto pointer = std::make_shared<int>(5);
			{
				List<std::shared_ptr<int>> list;
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				list.pushFront(std::shared_ptr<int>(pointer));
				Assert::IsTrue(pointer.use_count() == 6);
			}
			Assert::IsTrue(pointer.use_count() == 1);
		}
		TEST_METHOD(EmptyEmpty)
		{
			List<int> list;
			Assert::IsTrue(list.empty());
		}
		TEST_METHOD(EmptyOneElement)
		{
			List<int> list;
			list.pushFront(1);
			Assert::IsFalse(list.empty());
		}
		TEST_METHOD(EmptyTwoElements)
		{
			List<int> list;
			list.pushFront(1);
			list.pushFront(2);
			Assert::IsFalse(list.empty());
		}
	};
}
