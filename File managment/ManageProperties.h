#pragma once
#include"FileManager.h"

class ManageProperties:public FileManager<Properties>
{
public:
	ManageProperties(std::string path);
	virtual void put(Properties obj)const override;
	virtual std::vector<Properties> get()const override;
    std::vector<Properties> getPropertiesByOwner(size_t owner_id)const;
private:

};

inline ManageProperties::ManageProperties(std::string path):FileManager(path) {}

inline void ManageProperties::put(Properties prop)const
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << prop.square_meter << '\n' << prop.address << '\n' << prop.has_building << "\n\n";
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
	
}
