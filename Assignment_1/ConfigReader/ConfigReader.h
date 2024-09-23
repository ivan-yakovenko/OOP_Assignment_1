#pragma once
#include "../Airplane/Airplane.h"
#include "../FileHandler/FileHandler.h"
#include "../FileCloser/FileCloser.h"
#include <sstream>

class ConfigReader {
public:
    std::vector<Airplane> getAirplanesInfo(std::string& filename);
private:
    using filePtr = std::unique_ptr<FileHandler, FileCloser>;
    void seatsGenerator(int seatsPerRow, int startRow, int endRow, std::string& price, std::unordered_map<std::string, std::string>& priceForSeat);
    void readLine(char* buffer, ssize_t returnValue, std::string &line, std::vector<Airplane> &airplanes);
    void tokenizeLine(std::string &line, std::vector<Airplane> &airplanes);
};