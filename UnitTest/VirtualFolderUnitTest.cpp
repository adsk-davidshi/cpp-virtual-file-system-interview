// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: standalone VirtualFolder defaults.

#include "pch.h"
#include "CppUnitTest.h"
#include "..\VirtualFileSystem\VirtualFolder.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualFolderUnitTest)
	{
	public:
		TEST_METHOD(VirtualFolder_Name_Should_Default_Empty)
		{
			VirtualFolder folder;
			Assert::IsTrue(folder.getName().empty());
		}
	};
}
