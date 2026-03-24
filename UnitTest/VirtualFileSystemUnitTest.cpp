// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: basic folder creation, lookup, and path behavior.

#include "pch.h"
#include "CppUnitTest.h"
#include "..\VirtualFileSystem\VirtualFileSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualFileSystemUnitTest)
	{
	public:
		TEST_METHOD(VirtualFileSystem_Should_Not_Allow_Add_Root_To_Child_Folder)
		{
			auto initFS = [] {
				VirtualFileSystem fs;
				fs.getRoot().CreateFolder("$");
			};
			Assert::ExpectException<std::exception>(initFS);
		}
		TEST_METHOD(VirtualFileSystem_Should_Not_Allow_Add_Folder_With_Empty_Name)
		{
			auto initFS = [] {
				VirtualFileSystem fs;
				fs.getRoot().CreateFolder("");
			};
			Assert::ExpectException<std::exception>(initFS);
		}

		TEST_METHOD(VirtualFileSystem_Should_Not_Create_Same_Folder_Twice)
		{
			VirtualFileSystem fs;
			const VirtualFolder* folderA = fs.getRoot().CreateFolder("A");
			const VirtualFolder* folderB = fs.getRoot().CreateFolder("A");
			Assert::IsNotNull(folderA);
			Assert::IsNotNull(folderB);
			Assert::IsTrue(folderA == folderB);
		}

		TEST_METHOD(VirtualFileSystem_Should_Return_Full_Path_Properly_1)
		{
			VirtualFileSystem fs;
			const VirtualFolder* folderA = fs.getRoot().CreateFolder("A");
			Assert::IsNotNull(folderA);
			auto str = folderA->getPath();
			Assert::IsTrue(str == "$/A");
			const VirtualFolder* folderB = const_cast<VirtualFolder*>(folderA)->CreateFolder("B");
			Assert::IsNotNull(folderB);
			str = folderB->getPath();
			Assert::IsTrue(str == "$/A/B");
		}

		TEST_METHOD(VirtualFileSystem_Should_Return_Full_Path_Properly_2)
		{
			VirtualFileSystem fs;
			const VirtualFolder* folderB = fs.getRoot().CreateFolder("A/B");
			Assert::IsNotNull(folderB);
			Assert::IsTrue(folderB->getPath() == "$/A/B");
			const VirtualFolder* folderD = fs.getRoot().CreateFolder("A/B/C/D");
			Assert::IsNotNull(folderD);
			Assert::IsTrue(folderD->getPath() == "$/A/B/C/D");
		}

		TEST_METHOD(VirtualFileSystem_Should_Return_Folder_By_Name)
		{
			VirtualFileSystem fs;
			const VirtualFolder* folderA = fs.getRoot().CreateFolder("A");
			const VirtualFolder* queriedFolderA = fs.getRoot().GetFolder("A");
			Assert::IsNotNull(folderA);
			Assert::IsNotNull(queriedFolderA);
			Assert::IsTrue(folderA == queriedFolderA);
			const VirtualFolder* folderC = const_cast<VirtualFolder*>(folderA)->CreateFolder("B/C");
			const VirtualFolder* queriedFolderC = fs.getRoot().GetFolder("A/B/C");
			Assert::IsNotNull(folderC);
			Assert::IsNotNull(queriedFolderC);
			Assert::IsTrue(folderC == queriedFolderC);
		}
	};
}
