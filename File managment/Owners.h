#pragma once
#include<iostream>
#include<fstream>
#include<string>
using OwnerName = std::pair<std::string, std::string>;
class Owners
{
public:
	OwnerName user;
	std::string telephone="";
	int age = 0;
	size_t id = 0;
};
inline std::ostream& operator<<(std::ostream& os, const Owners& owner)
{
	os << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age << '\n' << owner.id << "\n\n";
	return os;
}
inline std::istream& operator>>(std::istream& is,  Owners& owner) {
	is >> owner.user.first;
	is.ignore(1);
	is >> owner.user.second;
	is.ignore(1);
	is >> owner.telephone;
	is.ignore(1);
	is >> owner.age;
	is.ignore(1);
	is >> owner.id;
	is.ignore(2);
	return is;
}
