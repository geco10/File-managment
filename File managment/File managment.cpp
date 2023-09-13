#include <iostream>
#include"Owners.h"
#include"FileManager.h"
std::ostream& operator<<(std::ostream& os, const Owners& owner)
{
    os << owner.user.first << '\n' << owner.user.second << '\n' << owner.telephone << '\n' << owner.age << "\n\n";
    return os;
}

int main()
{
    Owners owner;
    owner.age = 52;
    owner.telephone = "2814336856";
    owner.user.first = "Tim";
    owner.user.second = "Copeland";
    FileManager manage("Owners.txt");
    manage.create();
    manage.putO(owner);
    owner.age = 143;
    owner.telephone = "281leakgeeks";
    owner.user.first = "doctor";
    owner.user.second = "Mckenzie";
    manage.putO(owner);
    for (Owners owner : manage.getOwners())
        std::cout << owner;
}