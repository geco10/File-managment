#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"


int main()
{
	ManageOwners manage("Owners.txt");
	manage.remove_by_id(1);
	for (auto prop : manage.get())
		std::cout << prop;
}