#pragma once
#include<fstream>
#include<string>
#include"Owners.h"
#include"Properties.h"
#include<vector>

class FileManager
{
	std::string path;
public:
	virtual void putO(Owners owner);
	virtual void putP(Properties prop);
	void open(std::string path);
	FileManager(std::string path);
	void create();
	virtual std::vector<Owners> getOwners();
	virtual std::vector<Properties> getProperties();
};		

#include"FileManager.h"
 

 
inline void FileManager::open(std::string path)
{
	this->path = path;
}
 
inline FileManager::FileManager(std::string path)
{
	open(path);
}
 
inline void FileManager::create()
{
	std::ofstream fout;
	fout.open(path);
	fout.close();
}
 
