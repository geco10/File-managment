#pragma once
#include"FileManager.h"
class ManageOwners :public FileManager<Owners>
{
	int get_last_id()const;
	void change_id(int a)const;
public:
	void remove_by_id(size_t id);
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

inline void ManageOwners::remove_by_id(size_t id)
{
	remove([id](const Owners& owner) {
		return owner.id == id;
	});
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
	return get_data();
}
