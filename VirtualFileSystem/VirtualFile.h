#pragma once
#include "IVirtualNode.h"
class VirtualFile : public IVirtualNode
{
public:
	VirtualFile();
	VirtualFile(const std::string& name);
	~VirtualFile();

	// Overrides
	virtual const std::string& getName() const override;
	virtual void setName(const std::string&) override;
	virtual void Rename(const std::string&) override;
	virtual const IVirtualNode& getParent() override;
	virtual void setParent(const IVirtualNode&) override;
	virtual const std::string& getPath() const override;

	virtual const IVirtualNode& copyTo(const IVirtualNode& dest) override;
	virtual const IVirtualNode& moveTo(const IVirtualNode& dest) override;

private:
	std::string m_name;
	IVirtualNode* m_parent;
};

