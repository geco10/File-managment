#pragma once
#include<fstream>
#include<string>
#include"Owners.h"
#include"Properties.h"
#include<vector>
template <typename Type>
class FileManager
{
	std::string path;
public:
	void put(Type type);
	void open(std::string path);
	FileManager(std::string path);
	void create();
	std::vector<Type> get();
};
#include"FileManager.h"
template <typename Type>
inline void FileManager<Type>::put(Type type)
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	if(Type==Owners)
	  fout << type.user.first << '\n' << type.user.second << '\n' << type.telephone << '\n' << type.age << "\n\n";
	else
		fout << type.square_meter << '\n' << type.address << '\n' << type.has_building << "\n\n";
	fout.close();
}
template <typename Type>
inline void FileManager<Type>::open(std::string path)
{
	this->path = path;
}
template <typename Type>
inline FileManager<Type>::FileManager(std::string path)
{
	open(path);
}
template <typename Type>
inline void FileManager<Type>::create()
{
	std::ofstream fout;
	fout.open(path);
	fout.close();
}
template <typename Type>
inline std::vector<Type> FileManager<Type>::get()
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Type> a;
	if (Type == Owners) {
		while (fin.eof()) {
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
	}
	else
	{
		while (fin.eof()) {
			Properties prop;
			fin >> prop.square_meter;
			fin.ignore(1);
			fin >> prop.address;
			fin.ignore(1);
			fin >> owner.has_building;
			fin.ignore(2);
		}
	}
	fin.close();
	return a;

}

