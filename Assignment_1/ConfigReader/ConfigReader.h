#pragma once
#include "../Airplane/Airplane.h"
#include <fstream>
#include <sstream>
class ConfigReader {
public:
    std::vector<Airplane> getAirplanesInfo(std::string& filename);
private:
    void seatsGenerator(int seatsPerRow, int startRow, int endRow, std::string& price, std::unordered_map<std::string, std::string>& priceForSeat);
};