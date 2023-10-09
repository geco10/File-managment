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
	std::vector<Type> get_data()const;
public:
	template<typename DelegateFunction>
	void remove(DelegateFunction function);
	template<typename DelegateFunction, typename UpdateFunction>
	void update(DelegateFunction function,UpdateFunction update);
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
inline std::vector<Type> FileManager<Type>::get_data() const
{
	std::ifstream fin;
	fin.open(path);
	std::vector<Type> a;
	while (!fin.eof()) {
		Type o;
		fin >> o;
		a.push_back(o);
	}
	fin.close();
	return a;
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
 
template<typename Type>
template<typename DelegateFunction>
inline void FileManager<Type>::remove(DelegateFunction function)
{
	std::vector<Type> a = get();
	std::ofstream fout;
	fout.open(path);
	for (int i = 0; i < a.size(); i++) {
		if (!function(a[i]))
			fout << a[i];
	}
	fout.close();
}

template<typename Type>
template<typename DelegateFunction,typename UpdateFunction>
inline void FileManager<Type>::update(DelegateFunction function, UpdateFunction update)
{
	std::vector<Type> a = get();
	std::ofstream fout;
	fout.open(path);
	for (int i = 0; i < a.size(); i++) {
		if (function(a[i]))
			fout << update(a[i]);
		else
			fout << a[i];
	}
	fout.close();
}
