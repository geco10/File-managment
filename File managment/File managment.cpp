#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"

int main()
{
    Owners owners;
    owners.age =  30;
    owners.telephone = "1201knockknock";
    owners.user.second = "figjskr";
    owners.user.first = "grej";
    owners.id = 1;
    ManageOwners manage("Owners.txt");
    manage.put(owners);
    for (Owners owners : manage.get())
        std::cout << owners;
}