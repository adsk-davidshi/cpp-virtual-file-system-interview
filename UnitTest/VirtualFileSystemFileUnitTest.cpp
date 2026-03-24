// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: file creation, lookup, path validation, and file/folder conflicts.

#include "pch.h"
#include "CppUnitTest.h"
#include "..\VirtualFileSystem\VirtualFileSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualFileSystemFileUnitTest)
	{
	public:
		TEST_METHOD(VirtualFileSystem_Should_Throw_InvalidArgument_For_Invalid_Path)
		{
			auto createInvalidPath = [] {
				VirtualFileSystem fs;
				fs.getRoot().CreateFolder("A//B");
			};
			Assert::ExpectException<std::invalid_argument>(createInvalidPath);
		}

		TEST_METHOD(VirtualFileSystem_Should_Create_And_Get_Nested_File)
		{
			VirtualFileSystem fs;
			const VirtualFile* file = fs.getRoot().CreateFile("A/B.txt");
			Assert::IsNotNull(file);
			Assert::IsTrue(file->getPath() == "$/A/B.txt");
			Assert::IsTrue(file == fs.getRoot().GetFile("A/B.txt"));
		}

		TEST_METHOD(VirtualFileSystem_Should_Reject_File_And_Folder_Name_Conflict)
		{
			auto createConflict = [] {
				VirtualFileSystem fs;
				fs.getRoot().CreateFile("A");
				fs.getRoot().CreateFolder("A");
			};
			Assert::ExpectException<std::logic_error>(createConflict);
		}
	};
}
