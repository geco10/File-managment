#pragma once
#include"FileManager.h"
class ManageProperties:public FileManager
{
public:
	virtual void putP(Properties prop);
	virtual std::vector<Properties> getProperties();

private:

};

inline void ManageProperties::putP(Properties prop)
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << prop.square_meter << '\n' << prop.address << '\n' << prop.has_building << "\n\n";
	fout.close();
}
inline std::vector<Properties> ManageProperties::getProperties()
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Properties> a;
	while (fin.eof()) {
		Properties prop;
		fin >> prop.square_meter;
		fin.ignore(1);
		fin >> prop.address;
		fin.ignore(1);
		fin >> prop.has_building;
		fin.ignore(2);
	}
	fin.close();
	return a;

}