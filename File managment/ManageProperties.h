#pragma once
#include"FileManager.h"

class ManageProperties:public FileManager<Properties>
{
public:
	ManageProperties(std::string path);
	virtual void put(const Properties& obj)const override;
	virtual std::vector<Properties> get()const override;
    std::vector<Properties> getPropertiesByOwner(size_t owner_id)const;
private:

};

inline ManageProperties::ManageProperties(std::string path):FileManager(path) {}

inline void ManageProperties::put(const Properties& prop)const
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << prop;
	fout.close();
}
inline std::vector<Properties> ManageProperties::get()const
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Properties> a;
	while (!fin.eof()) {
		Properties prop;
		fin >> prop;
		a.push_back(prop);
	}
	fin.close();
	return a;

}

inline std::vector<Properties> ManageProperties::getPropertiesByOwner(size_t last_id) const
{
	std::vector<Properties> data;
	std::ifstream fin;
	fin.open(path);
	while (!fin.eof()) {
		Properties prop;
		fin >> prop;
		data.push_back(prop);
	}
	fin.close();
	std::vector<Properties> arr;
	for (int i = 0; i < data.size(); i++){
		if (data[i].id_owner == last_id)
			arr.push_back(data[i]);
	}
	return arr;
}
