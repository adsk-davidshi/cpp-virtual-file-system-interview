#pragma once
#include ".\Constants.h"
#include ".\VirtualFile.h"
#include ".\VirtualFolder.h"
#include ".\VirtualRootFolder.h"
class VirtualFileSystem
{
public:
	VirtualFileSystem();
	~VirtualFileSystem();
	void Init();
	VirtualFolder& getRoot();

	const std::string& getSeparator() { return FS_FOLDER_SEPARATOR; };
	const std::string& getRootName() { return FS_FOLDER_ROOT_NAME; };

private:
	VirtualRootFolder m_root;
};

