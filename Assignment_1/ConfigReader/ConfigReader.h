#pragma once

#include "../Airplane/Airplane.h"
#include <sstream>
#include <fcntl.h>
#include <unistd.h>

class FileHandler {
public:
//    std::vector<Airplane> getAirplanesInfo(std::string& filename);
    FileHandler();

    FileHandler(std::string &filename);

    ~FileHandler();

    FileHandler(FileHandler &other);

    FileHandler &operator=(FileHandler &other);

    FileHandler(FileHandler &&other);

    FileHandler &operator=(FileHandler &&other);

private:
    int fileDescriptor;
//    void seatsGenerator(int seatsPerRow, int startRow, int endRow, std::string& price, std::unordered_map<std::string, std::string>& priceForSeat);
};