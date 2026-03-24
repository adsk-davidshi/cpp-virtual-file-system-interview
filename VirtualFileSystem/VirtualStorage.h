#pragma once
#include <map>
#include "IVirtualNode.h"
class VirtualStorage
{
private:
	VirtualStorage() {};
	~VirtualStorage() {};
	VirtualStorage(const VirtualStorage&);
	VirtualStorage& operator=(const VirtualStorage&);

public:
	static VirtualStorage& instance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new VirtualStorage;
		}
		return *m_instance;
	}

	void allocate(IVirtualNode* node);
	void deAllocate(IVirtualNode* node);

private:
	static VirtualStorage* m_instance;

	std::map<const std::string, int> m_fileStorageIndex;
	static unsigned int m_index;
};

