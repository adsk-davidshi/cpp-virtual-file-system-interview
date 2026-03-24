// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: child listing order and basic concurrent read behavior.

#include "pch.h"
#include "CppUnitTest.h"
#include <atomic>
#include <thread>
#include "..\VirtualFileSystem\VirtualFileSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualFileSystemTraversalConcurrencyUnitTest)
	{
	public:
		TEST_METHOD(VirtualFileSystem_Should_List_Direct_Children_In_Name_Order)
		{
			VirtualFileSystem fs;
			fs.getRoot().CreateFolder("B");
			fs.getRoot().CreateFile("A.txt");
			fs.getRoot().CreateFolder("A");

			const auto children = fs.getRoot().ListChildren();

			Assert::IsTrue(children.size() == 3);
			Assert::IsTrue(children[0]->getName() == "A");
			Assert::IsTrue(children[1]->getName() == "A.txt");
			Assert::IsTrue(children[2]->getName() == "B");
		}

		TEST_METHOD(VirtualFileSystem_Should_Support_Basic_Concurrent_Reads)
		{
			VirtualFileSystem fs;
			fs.getRoot().CreateFolder("A/B");
			fs.getRoot().CreateFile("A/file.txt");

			std::atomic<bool> success(true);
			auto readTask = [&]() {
				for (int i = 0; i < 100; ++i)
				{
					const VirtualFolder* folder = fs.getRoot().GetFolder("A/B");
					const VirtualFile* file = fs.getRoot().GetFile("A/file.txt");
					if (folder == nullptr || file == nullptr)
					{
						success = false;
						return;
					}
					if (folder->getPath() != "$/A/B" || file->getPath() != "$/A/file.txt")
					{
						success = false;
						return;
					}
				}
			};

			std::thread t1(readTask);
			std::thread t2(readTask);
			std::thread t3(readTask);

			t1.join();
			t2.join();
			t3.join();

			Assert::IsTrue(success.load());
		}
	};
}
