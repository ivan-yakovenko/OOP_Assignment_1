#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>

#include "../Ticket/Ticket.h"

class Airplane {
private:
    std::string date;
    std::string flightNo;
    std::unordered_map<std::string, std::string> priceForSeat;
    std::unordered_map<std::string, std::string> bookedSeat;
    std::vector<Ticket> bookedTickets;
//    bool isAvailable;
public:
    Airplane();

    Airplane(std::string date, std::string flightNo,
             std::unordered_map<std::string, std::string> priceForSeat,
             std::unordered_map<std::string, std::string> bookedSeat,
             std::vector<Ticket> bookedTickets);

//    std::string getDate() const;
//
//    std::string getFlightNo() const;
//
//    int getSeatsPerRow() const;
//
//    std::unordered_map<std::string, std::string> getPriceForSeat() const;

//    bool getIsAvailable() const;

//    void setDate(std::string &date);
//
//    void setFlightNo(std::string &flightNo);
//
//    void setSeatsPerRow(int seatsPerRo);
//
//    void setPriceForSeat(std::unordered_map<std::string, std::string> &priceForSeat);

//    void setIsAvailable(bool isAvailable);

    std::vector<Ticket> getBookedTickets() const;

    void generalPrint() const;

    void printPlaces() const;

    void check(std::string &date, std::string &flightNo) const;

    void book(std::string &date, std::string &flightNo, std::string &seat, std::string &username);

    void returnTicket(long bookedID);

    void viewByID(long bookedID);

    void viewByUsername(std::string &username);

    void viewByFlightNumber(std::string &flightNo);
};