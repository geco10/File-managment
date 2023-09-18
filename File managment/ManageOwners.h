#pragma once
#include"FileManager.h"
class ManageOwners :public FileManager<Owners>
{
	int get_last_id()const;
	void change_id(int a)const;
public:
	ManageOwners(std::string path);
	virtual void put(Owners owner)const override;
	virtual std::vector<Owners> get()const override;
};

#include"ManageOwners.h"
inline int ManageOwners::get_last_id()const
{
	std::ifstream fin;
	fin.open("Last_owner_id.txt");
	int b;
	fin>>b;
	fin.close();
	return b;
}
inline void ManageOwners::change_id(int a)const
{
	std::ofstream fout;
	fout.open("Last_owner_id.txt");
	fout << a;
	fout.close();
}
inline ManageOwners::ManageOwners(std::string path) :FileManager(path) {}
inline void ManageOwners::put(Owners owner)const
{
	int last_id = get_last_id();
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age <<owner.id<< "\n\n";
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