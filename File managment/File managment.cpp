#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"


int main()
{
    Properties prop;
    prop.square_meter =  30;
    prop.address = "1201knockknock";
    prop.has_building = true;
    ManageProperties manage("Properties.txt");
    manage.put(prop);
    prop.square_meter = 40;
    prop.address = "12knockknocis";
    prop.has_building = false;
    manage.put(prop);
    Owners owner;
    owner.age = 2;
    owner.user.first = "coco";
    owner.user.second = "melon";
    owner.telephone="281knockboom";
    ManageOwners manage("Owners.txt");
    for (Properties prop : manage.getPropertiesByOwner(2))
        std::cout << prop;
}