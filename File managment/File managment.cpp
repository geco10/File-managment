#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"


int main()
{
	ManageProperties manage("Properties.txt");
	ManageOwners manageO("Owners.txt");
	int i = 0;
	for (Owners owner : manageO.get()) {
		std::vector<Properties> arr = manage.getPropertiesByOwner(i);
		std::cout << owner.user.first << " ";
		for (Properties prop : arr)
			std::cout << prop.address<<" ";
		puts("");
		i++;
	}
}