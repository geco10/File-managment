#include <iostream>
#include"Database.h"
#include"Owners.h"
#include"Properties.h"

//void checkO(){
//	ManageOwners manage("Owners.txt");
//	manage.update([](const Owners& owner) {
//	  return owner.id == 2;
//	},
//	[](Owners& owner) {
//		owner.age = 100;
//		return owner;
//	});
//	for (auto prop : manage.get())
//		std::cout << prop;
//}
//void checkP() {
//	ManageProperties manage("Properties.txt");
//	manage.update([](const Properties& prop) {
//		return prop.address == "saint.st";
//	},
//	[](Properties& prop) {
//		prop.square_meter = 1;
//		return prop;
//	});
//	for (auto prop : manage.get())
//		std::cout << prop;
//}


int main()
{
    Database::init("Owners.txt","Properties.txt");
    std::vector<Owners> data=Database::getObject().getOwnersWithBuilding();
    for (auto o : data) {
        std::cout << o<<"\n";
    }
}