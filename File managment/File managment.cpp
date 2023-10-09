#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"
void checkO(){
	ManageOwners manage("Owners.txt");
	manage.update([](const Owners& owner) {
	  return owner.id == 2;
	},
	[](Owners& owner) {
		owner.age = 100;
		return owner;
	});
	for (auto prop : manage.get())
		std::cout << prop;
}
void checkP() {
	ManageProperties manage("Properties.txt");
	manage.update([](const Properties& prop) {
		return prop.address == "saint.st";
	},
	[](Properties& prop) {
		prop.square_meter = 1;
		return prop;
	});
	for (auto prop : manage.get())
		std::cout << prop;
}


int main()
{
	ManageProperties manage("Properties.txt");
	ManageOwners manageO("Owners.txt");
	manageO.update([&manage](const Owners& owner) {
		std::vector<Properties> a=manage.getPropertiesByOwner(owner.id);
		for (int i = 0; i < a.size(); i++) {
			if (a[i].has_building)
				return true;
		}
		return false;
		},
		[](Owners& owner) {
			owner.user.first = "Petya";
			return owner;
			});
	for (auto prop : manageO.get())
		std::cout << prop;
}