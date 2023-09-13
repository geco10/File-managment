#pragma once
#include"FileManager.h"
class ManageOwners :public FileManager
{

public:
	virtual void putO(Owners owner);
	virtual std::vector<Owners> getOwners();
};

#include"ManageOwners.h"
inline void ManageOwners::putO(Owners owner)
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age << "\n\n";
	fout.close();
}
inline std::vector<Owners> ManageOwners::getOwners()
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Owners> a;
	while (!fin.eof()) {
		Owners owner;
		fin >> owner.user.first;
		fin.ignore(1);
		fin >> owner.user.second;
		fin.ignore(1);
		fin >> owner.telephone;
		fin.ignore(1);
		fin >> owner.age;
		fin.ignore(2);
		a.push_back(owner);
	}
	fin.close();
	return a;

}