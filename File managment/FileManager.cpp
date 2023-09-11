#include "FileManager.h"

void FileManager::put(Owners owner)
{
	std::ofstream fout;
	fout.open(path,std::ios_base::app);
	fout << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age << "\n\n";
	fout.close();
}

void FileManager::open(std::string path)
{
	this->path = path;
}

FileManager::FileManager(std::string path)
{
	open(path);
}

void FileManager::create()
{
	std::ofstream fout;
	fout.open(path);
	fout.close();
}

std::vector<Owners> FileManager::get()
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Owners> a;
	while (fin.eof()) {
		Owners owner;
		fin >> owner.user.first;
		fin.ignore(1);
		fin >> owner.user.second;
		fin.ignore(1);
		fin >> owner.telephone;
		fin.ignore(1);
		fin>> owner.age;
		fin.ignore(2);
		a.push_back(owner);
	}
	return a;
	fin.close();
}
