
#include "Database.h"
Database* Database:: object  = nullptr;
std::vector<Owners> Database::getOwners()
{
    return mo.get();
}
std::vector<Properties> Database::getProperties()
{
    return po.get();
}
Database& Database::getObject()
{
    if (object == nullptr)
        throw"now init";
    else
        return *object;
}
std::vector<Owners> Database::getOwnersWithBuilding()
{
    std::vector<Owners> data;
    std::vector<Owners> dataO = mo.get();
    std::vector<Properties> dataP = po.get();
    for (int i = 0; i < dataO.size(); ++i) {
        for (int j = 0; j < dataP.size(); ++j) {
            if (dataP[j].id_owner == dataO[i].id && dataP[j].has_building == true){
                data.push_back(dataO[i]); 
                break;
            }
        }
    }
    return data;
}
Database::Database(std::string path, std::string path2) :mo(path),po(path2) {}
void Database::init(std::string path,std::string path2)
{
    if (object != nullptr)
        throw"already init";
    else
       object=new Database(path,path2);
}
