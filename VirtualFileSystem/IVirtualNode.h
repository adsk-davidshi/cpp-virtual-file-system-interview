#pragma once
#include <string>
class IVirtualNode
{
public:
	virtual const std::string& getName() const = 0;
	virtual void setName(const std::string&) = 0;
	virtual void Rename(const std::string&) = 0;
	virtual const IVirtualNode& getParent() = 0;
	virtual void setParent(const IVirtualNode&) = 0;
	virtual const std::string& getPath() const = 0;

	virtual const IVirtualNode& copyTo(const IVirtualNode& dest) = 0;
	virtual const IVirtualNode& moveTo(const IVirtualNode& dest) = 0;
};

