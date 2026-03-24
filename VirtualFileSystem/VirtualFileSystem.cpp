#include "VirtualFileSystem.h"

VirtualFileSystem::VirtualFileSystem()
{
	Init();
}

VirtualFileSystem::~VirtualFileSystem()
{
}

void VirtualFileSystem::Init()
{
	m_root = VirtualRootFolder();
}

VirtualFolder& VirtualFileSystem::getRoot()
{
	return m_root;
}