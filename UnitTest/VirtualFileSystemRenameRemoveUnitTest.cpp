// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: path-based remove and rename behavior.

#include "pch.h"
#include "CppUnitTest.h"
#include "..\VirtualFileSystem\VirtualFileSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualFileSystemRenameRemoveUnitTest)
	{
	public:
		TEST_METHOD(VirtualFileSystem_Should_Remove_Node_By_Relative_Path)
		{
			VirtualFileSystem fs;
			fs.getRoot().CreateFile("A/B.txt");
			Assert::IsTrue(fs.getRoot().Remove("A/B.txt"));
			Assert::IsTrue(fs.getRoot().GetFile("A/B.txt") == nullptr);
		}

		TEST_METHOD(VirtualFileSystem_Should_Rename_Folder_And_Update_Descendant_Path)
		{
			VirtualFileSystem fs;
			const VirtualFolder* folder = fs.getRoot().CreateFolder("A/B");
			VirtualFolder* topLevelFolder = const_cast<VirtualFolder*>(fs.getRoot().GetFolder("A"));
			Assert::IsNotNull(topLevelFolder);
			topLevelFolder->Rename("X");
			Assert::IsTrue(fs.getRoot().GetFolder("A/B") == nullptr);
			Assert::IsTrue(folder->getPath() == "$/X/B");
			Assert::IsTrue(fs.getRoot().GetFolder("X/B") == folder);
		}
	};
}
