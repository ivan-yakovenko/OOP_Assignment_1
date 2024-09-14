#pragma once
#include "../ConfigReader/ConfigReader.h"

class CLI {
private:
    ConfigReader configReader;
    std::string filePath;
    std::vector<Airplane> airplanes;
    void checkPlaces(std::string &date, std::string &flightNo);
    void bookSeat(std::string &date, std::string &flightNo, std::string &seat, std::string &username);
    void returnTicket(long bookedID);
    void viewID(long bookedID);
    void viewUsername(std::string &username);
    void viewFlightNo(std::string &flightNo);
    bool validCommand(std::string &command);
    bool checkIfId(std::string &parameter);
public:
    CLI(std::string &filePath);
    void run();
};