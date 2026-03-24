#include "VirtualFile.h"

VirtualFile::VirtualFile() : m_name(""), m_parent(nullptr)
{
}

VirtualFile::VirtualFile(const std::string& name)
{
}

VirtualFile::~VirtualFile()
{
}

const std::string& VirtualFile::getName() const
{
	return m_name;
}

void VirtualFile::setName(const std::string& name)
{

}

void VirtualFile::Rename(const std::string& name)
{
}

const IVirtualNode& VirtualFile::getParent()
{
	return *m_parent;
}

void VirtualFile::setParent(const IVirtualNode& parent)
{
}

const std::string& VirtualFile::VirtualFile::getPath() const
{
	return m_name;
}

const IVirtualNode& VirtualFile::copyTo(const IVirtualNode& dest)
{
	return *this;
}

const IVirtualNode& VirtualFile::moveTo(const IVirtualNode& dest)
{
	return *this;
}
