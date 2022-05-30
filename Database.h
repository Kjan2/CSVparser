#include <string>
#include <map>
#include <fstream>
#include <vector>

typedef unsigned int uint;

class Database
{
public:
    Database() = default;
    Database(std::fstream& file);
    uint getOtherMonthlyCosts(const std::string& city, uint age);
    uint getHomeFoodCost(const std::string& city);
    uint getCinemaCost(const std::string& city, const std::string& cinema);
    uint getCoffeeCost(const std::string& city, const std::string& coffee);
    uint getInstituteDinnerCost(const std::string& city, const std::string& institute);
    uint getTransportCost(const std::string& city, const std::string& homeAddress,
                      const std::string& institute);
    
private:
    std::map<std::string, std::vector<std::string>> _data;
};
