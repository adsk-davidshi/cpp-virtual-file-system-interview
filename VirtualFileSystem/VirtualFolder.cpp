#include "VirtualFile.h"
#include "VirtualFolder.h"

VirtualFolder::VirtualFolder() : m_name(""), m_parent(nullptr)
{
}

VirtualFolder::VirtualFolder(const std::string& name) : m_name(name), m_parent(nullptr)
{
}

VirtualFolder::~VirtualFolder()
{
}

const std::string& VirtualFolder::getName() const
{
	return m_name;
}

void VirtualFolder::setName(const std::string& name)
{

}

void VirtualFolder::Rename(const std::string& name)
{
}

const IVirtualNode& VirtualFolder::getParent()
{
	return *m_parent;
}

void VirtualFolder::setParent(const IVirtualNode& parent)
{
}

const std::string& VirtualFolder::VirtualFolder::getPath() const
{
	return m_name;
}

const IVirtualNode& VirtualFolder::copyTo(const IVirtualNode& dest)
{
	return *this;
}

const IVirtualNode& VirtualFolder::moveTo(const IVirtualNode& dest)
{
	return *this;
}

const VirtualFile* VirtualFolder::CreateFile(std::string fileName)
{
	return nullptr;
}

const VirtualFolder* VirtualFolder::CreateFolder(std::string folderName)
{
	return nullptr;
}

const VirtualFile* VirtualFolder::GetFile(std::string fileName)
{
	return nullptr;
}

const VirtualFolder* VirtualFolder::GetFolder(std::string folderName)
{
	return nullptr;
}

bool VirtualFolder::Remove(std::string path)
{
	return false;
}

std::vector<const IVirtualNode*> VirtualFolder::ListChildren() const
{
	return {};
}

bool VirtualFolder::remove()
{
	return false;
}