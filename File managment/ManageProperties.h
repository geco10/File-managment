#pragma once
#include"FileManager.h"

class ManageProperties:public FileManager<Properties>
{
protected:
    
public:
	ManageProperties(std::string path);
	virtual void put(const Properties& obj)const override;
	void remove_by_address(std::string address);
	virtual std::vector<Properties> get()const override;
    std::vector<Properties> getPropertiesByOwner(size_t owner_id)const;
private:

};



inline ManageProperties::ManageProperties(std::string path):FileManager(path) {}

inline void ManageProperties::put(const Properties& prop)const
{
	put_data(prop);
}
inline void ManageProperties::remove_by_address(std::string address)
{
	remove([address](const Properties& prop) {
		return prop.address == address;
	});
}
inline std::vector<Properties> ManageProperties::get()const
{
	return get_data();

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
