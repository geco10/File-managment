#pragma once
#include"Owners.h"
#include<fstream>
#include<string>
#include<vector>
class FileManager
{
	std::string path;
public:
	void put(Owners owner);
	void open(std::string path);
	FileManager(std::string path);
	void create();
	std::vector<Owners> get();
};

