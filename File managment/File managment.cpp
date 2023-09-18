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
    for (Properties prop : manage.get())
        std::cout << prop;
}