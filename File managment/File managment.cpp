#include <iostream>
#include"Owners.h"
#include"ManageOwners.h"
#include"ManageProperties.h"


int main()
{
	ManageProperties manage("Properties.txt");
	for (Properties prop : manage.get())
		std::cout << prop;
 }