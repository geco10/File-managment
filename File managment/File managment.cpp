#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"


int main()
{
	Owners owner;
	owner.age = 25;
	owner.telephone = "658299044";
	owner.user.first = "tommda";
	owner.user.second = "terresa";
	ManageOwners manage("Owners.txt");
	manage.put(owner);
}