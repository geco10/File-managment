#include <iostream>
#include"Owners.h"
#include"FileManager.h"
template <typename Type>
int main()
{
    Owners owner;
    owner.age = 52;
    owner.telephone = "2814336856";
    owner.user.first = "Tim";
    owner.user.second = "Copeland";
    FileManager<Owners>manage("Owners.txt");
    manage.create();
    manage.put(owner);
    std::vector<Owners> owners= manage.get();
    printf("%i",owners[0].telephone);
}