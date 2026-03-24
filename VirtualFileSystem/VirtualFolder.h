#pragma once
#include <map>
#include <vector>
#include "constants.h"
#include "IVirtualNode.h"
#include "VirtualFile.h"

class VirtualFolder : public IVirtualNode
{
public:
	VirtualFolder();
	VirtualFolder(const std::string& name);
	~VirtualFolder();

	// Overrides
	virtual const std::string& getName() const override;
	virtual void setName(const std::string&) override;
	virtual void Rename(const std::string&) override;
	virtual const IVirtualNode& getParent() override;
	virtual void setParent(const IVirtualNode&) override;
	virtual const std::string& getPath() const override;

	virtual const IVirtualNode& copyTo(const IVirtualNode& dest) override;
	virtual const IVirtualNode& moveTo(const IVirtualNode& dest) override;

	// Public Methods
	const VirtualFile* CreateFile(std::string fileName = "");
	const VirtualFolder* CreateFolder(std::string folderName = "");
	const VirtualFile* GetFile(std::string fileName);
	const VirtualFolder* GetFolder(std::string folderName);
	bool Remove(std::string path);
	std::vector<const IVirtualNode*> ListChildren() const;
	bool remove();

private:
	std::string m_name;
	IVirtualNode* m_parent;
	std::map<std::string, const IVirtualNode*> m_children;
};

