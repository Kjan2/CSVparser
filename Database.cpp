#include "Database.h"
#include <string>
#include <fstream>
#include <unordered_map>
#include <iostream>

using namespace std::string_literals;

typedef unsigned int uint;

Database::Database(std::fstream& file)
{
    std::string temp;
    getline(file, temp, '\n');
    std::string token;
    int pos = 0;
    int i = 0;
    std::vector<std::string> headers;

    while ((pos = temp.find(",")) != std::string::npos)
    {
        token = temp.substr(0, pos);
        headers.push_back(token);
        _data[headers[i++]];
        temp.erase(0, pos + 1);
    }
    temp.pop_back();

    headers.push_back(temp);
    
    while (getline(file, temp, '\n'))
    {
        int i = 0;

        while ((pos = temp.find(",")) != std::string::npos)
        {
            token = temp.substr(0, pos); 
            _data[headers[i++]].push_back(token);
            temp.erase(0, pos + 1);
        }
        temp.pop_back(); 

        _data[headers[i]].push_back(temp);
    }
}

uint Database::getOtherMonthlyCosts(const std::string& city,
        uint age)
{
    if (!_data.count("Other costs"s))
    {
        std::string excep("Wrong file");
        throw excep;
        return 0;
    }


    int sum = 0;
    int count = 0;


    for (int i = 0; i < _data["City"s].size(); i++)
    {
        if ((_data["City"s][i] == city) && (std::stoul(_data["Age"s][i]) == age))
        {
            sum += std::stoul(_data["Other costs"s][i]);

            count++;
        }
    }

    if (count == 0)
    {
        return 0;
    }

    return sum / count;
}

uint Database::getHomeFoodCost(const std::string& city)
{
    if (!_data.count("Other costs"s))
    {
        std::string excep("Wrong file");
        throw excep;
        return 0;
    }
    int sum = 0;
    int count = 0; 

    for (int i = 0; i < _data["City"s].size(); i++)
    {
        sum += std::stoul(_data["Average food cost per month"s][i]);
        count++;
    }

    if (count == 0)
    {
        return 0;
    }

    return sum / count;
}

