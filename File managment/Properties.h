#pragma once
#include<fstream>
#include<string>

class Properties
{
public:
	std::string address="";
	int square_meter=0;
	bool has_building;
	std::string last_name = "";
	std::string telephone = "";
};
inline std::ostream& operator<<(std::ostream& os, const Properties& prop)
{
	os << prop.square_meter << '\n' << prop.address << '\n' << prop.has_building << "\n\n";

	return os;
}
inline std::istream& operator>>(std::istream& is, Properties& prop) {
	is >> prop.square_meter;
	is.ignore(1);
	is >> prop.address;
	is.ignore(1);
	is >> prop.has_building;
	is.ignore(2);
	return is;
}

