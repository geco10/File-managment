#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"


int main()
{
	Properties prop;
	prop.id_owner=4;
	prop.has_building = true;
	prop.address = "tommda";
	prop.square_meter =81;
	ManageProperties manage("Properties.txt");
	manage.put(prop);
}