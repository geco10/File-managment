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
	void put_data(const Type& type)const;
public:
	virtual void put(const Type& obj)const=0;
	void open(std::string path);
	FileManager(std::string path);
	void create();
	virtual std::vector<Type> get()const=0;
};		
 

template<typename Type>
inline void FileManager<Type>::put_data(const Type& type)const
{
	std::ofstream fout;
	fout.open(path, std::ios_base::app);
	fout << type;
	fout.close();
}

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
 
