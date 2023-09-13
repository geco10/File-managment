#pragma once
#include"FileManager.h"
class ManageOwners :public FileManager<Owners>
{

public:
	ManageOwners(std::string path);
	virtual void put(Owners owner)const override;
	virtual std::vector<Owners> get()const override;
};

#include"ManageOwners.h"
inline ManageOwners::ManageOwners(std::string path) :FileManager(path) {}
inline void ManageOwners::put(Owners owner)const
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age << "\n\n";
	fout.close();
}
inline std::vector<Owners> ManageOwners::get()const
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