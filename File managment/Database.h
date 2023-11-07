#pragma once
#include"ManageOwners.h"
#include"ManageProperties.h"
class Database
{
public:
	
	
	std::vector<Owners> getOwners();
	std::vector<Properties> getProperties();
	static Database& getObject();
	std::vector<Owners> getOwnersWithBuilding();
	static void init(std::string path,std::string path2);
	void operator=(const Database& x) = delete;
	Database(const Database& x)=delete;
private:
	ManageOwners mo;
	ManageProperties po;
	static Database* object;
	~Database() = default;
	Database(std::string path,std::string path2);
};

