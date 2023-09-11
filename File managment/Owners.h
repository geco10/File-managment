#pragma once
#include<fstream>
#include<string>
using OwnerName = std::pair<std::string, std::string>;
class Owners
{
public:
	OwnerName user;
	std::string telephone="";
	int age = 0;
};

