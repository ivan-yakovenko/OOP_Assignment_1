#include "Airplane.h"

Airplane::Airplane() : date("Empty"), flightNo("Empty"), seatsPerRow(0), priceForSeat({}), isAvailable(true) {}

Airplane::Airplane(std::string date, std::string flightNo, int seatsPerRow, std::unordered_map<std::string, double> priceForSeat, bool isAvailable) : date(date), flightNo(flightNo), seatsPerRow(seatsPerRow), priceForSeat(priceForSeat), isAvailable(isAvailable) {}

std::string Airplane::getDate() const {
    return date;
}

std::string Airplane::getFlightNo() const {
    return flightNo;
}

int Airplane::getSeatsPerRow() const {
    return seatsPerRow;
}

std::unordered_map<std::string, double> Airplane::getPriceForSeat() const {
    return priceForSeat;
}

bool Airplane::getIsAvailable() const {
    return isAvailable;
}

void Airplane::setDate(std::string &date) {
    this->date = date;
}

void Airplane::setFlightNo(std::string &flightNo) {
    this->flightNo = flightNo;
}

void Airplane::setSeatsPerRow(int seatsPerRo) {
    this->seatsPerRow = seatsPerRow;
}

void Airplane::setPriceForSeat(std::unordered_map<std::string, double> &priceForSeat) {
    this->priceForSeat = priceForSeat;
}

void Airplane::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}