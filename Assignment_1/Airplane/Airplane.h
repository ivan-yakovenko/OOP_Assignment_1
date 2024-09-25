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
    std::unordered_map<long, Ticket> bookedTickets;
public:
    Airplane();

    Airplane(std::string date, std::string flightNo,
             std::unordered_map<std::string, std::string> priceForSeat,
             std::unordered_map<std::string, std::string> bookedSeat,
             std::unordered_map<long, Ticket> bookedTickets);

    std::string getDate() const;

    std::string getFlightNo() const;

    std::unordered_map<std::string, std::string> getPriceForSeat() const;

    std::unordered_map<long, Ticket> getBookedTickets() const;

    void printPlaces() const;

    void check(std::string &date, std::string &flightNo) const;

    void book(std::string &date, std::string &flightNo, std::string &seat, std::string &username);

    void returnTicket(long bookedID);

    void viewByID(long bookedID);
};