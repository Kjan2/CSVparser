#include "Database.h"
#include <string>
#include <fstream>
#include <utility>
#include <iostream>


int main()
{
    std::fstream file;
    file.open("Costs.csv");
    Database data(file);
    std::string v("Moscow");
    std::cout << data.getHomeFoodCost(v);
    return 0;
}
