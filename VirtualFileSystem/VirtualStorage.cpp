#include "VirtualStorage.h"
#include <assert.h>
VirtualStorage* VirtualStorage::m_instance = nullptr;
unsigned int VirtualStorage::m_index = 0;

void VirtualStorage::allocate(IVirtualNode* node)
{
	assert(node != nullptr);
	assert(m_fileStorageIndex.find(node->getName()) == m_fileStorageIndex.end());

	m_fileStorageIndex.insert(std::make_pair(node->getName(), m_index++));
}

void VirtualStorage::deAllocate(IVirtualNode* node)
{
	assert(node != nullptr);
	assert(m_fileStorageIndex.find(node->getName()) != m_fileStorageIndex.end());

	m_fileStorageIndex.erase(node->getName());
}