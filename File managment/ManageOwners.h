#pragma once
#include"FileManager.h"
class ManageOwners :public FileManager<Owners>
{
	int get_last_id()const;
	void change_id(int a)const;
public:
	ManageOwners(std::string path);
	virtual void put(const Owners& owner)const override;
	virtual std::vector<Owners> get()const override;
};

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
inline void ManageOwners::put(const Owners& owner)const
{
	int last_id = get_last_id();
	Owners o = owner;
	o.id = last_id;

	put_data(o);

	change_id(last_id+1);
}
inline std::vector<Owners> ManageOwners::get()const
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Owners> a;
	while (!fin.eof()) {
		Owners o;
		fin >> o;
		a.push_back(o);
	}
	fin.close();
	return a;

}
