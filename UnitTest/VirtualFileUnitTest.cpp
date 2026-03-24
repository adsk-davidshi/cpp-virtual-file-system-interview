// Test naming rule:
// - File name: <Subject>UnitTest.cpp or <Subject><Area>UnitTest.cpp
// - Test class: match the file name without extension
// - Test method: <Subject>_Should_<ExpectedBehavior>
//
// Scope: standalone VirtualFile defaults.

#include "pch.h"
#include "CppUnitTest.h"
#include "..\VirtualFileSystem\VirtualFile.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VirtualFileSystemUnitTest
{
	TEST_CLASS(VirtualFileUnitTest)
	{
	public:
		TEST_METHOD(VirtualFile_Name_Should_Default_Empty)
		{
			VirtualFile file;
			Assert::IsTrue(file.getName().empty());
		}
	};
}
