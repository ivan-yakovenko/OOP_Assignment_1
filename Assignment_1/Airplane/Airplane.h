#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
class Airplane {
private:
    std::string date;
    std::string flightNo;
    int seatsPerRow;
    std::unordered_map<std::string, double> priceForSeat;
    bool isAvailable;
public:
    Airplane();
    Airplane(std::string date, std::string flightNo, int seatsPerRow,
             std::unordered_map<std::string, double> priceForSeat, bool isAvailable);

    std::string getDate() const;
    std::string getFlightNo() const;
    int getSeatsPerRow() const;
    std::unordered_map<std::string, double> getPriceForSeat() const;
    bool getIsAvailable() const;

    void setDate(std::string& date);
    void setFlightNo(std::string& flightNo);
    void setSeatsPerRow(int seatsPerRo);
    void setPriceForSeat(std::unordered_map<std::string, double>& priceForSeat);
    void setIsAvailable(bool isAvailable);
};