#pragma once
#include<fstream>
#include<string>
#include"Owners.h"
#include"Properties.h"
#include<vector>
template<typename Type>
class FileManager
{
protected:
	std::string path;
public:
	virtual void put(Type obj)const=0;
	void open(std::string path);
	FileManager(std::string path);
	void create();
	virtual std::vector<Type> get()const=0;
};		
 

template<typename Type>
inline void FileManager<Type>::open(std::string path)
{
	this->path = path;
}
template<typename Type>

inline FileManager<Type>::FileManager(std::string path)
{
	open(path);
}
template<typename Type>

inline void FileManager<Type>::create()
{
	std::ofstream fout;
	fout.open(path);
	fout.close();
}
 
