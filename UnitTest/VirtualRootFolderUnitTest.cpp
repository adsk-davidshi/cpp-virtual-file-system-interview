// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: VirtualRootFolder identity rules.

#include "pch.h"
#include "CppUnitTest.h"
#include "..\VirtualFileSystem\Constants.h"
#include "..\VirtualFileSystem\VirtualFileSystem.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualRootFolderUnitTest)
	{
	public:
		TEST_METHOD(VirtualRootFolder_Name_Should_Be_Dollar)
		{
			VirtualRootFolder folder;
			Assert::IsTrue(folder.getName() == FS_FOLDER_ROOT_NAME);
		}
	};
}
