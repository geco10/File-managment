#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"
std::ostream& operator<<(std::ostream& os, const Owners& owner)
{
    os << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age << "\n\n";
    return os;
}
std::ostream& operator<<(std::ostream& os, const Properties& prop)
{
    os << prop.square_meter << '\n' << prop.address << '\n' << prop.has_building << "\n\n";

     return os;
}

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