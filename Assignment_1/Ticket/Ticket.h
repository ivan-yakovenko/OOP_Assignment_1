#pragma once

#include <iostream>

class Ticket {
private:
    std::string date;
    std::string flightNo;
    std::string seat;
    std::string price;
    std::string username;
    long bookedID;
public:
    Ticket();

    Ticket(std::string date, std::string flightNo, std::string seat, std::string price, std::string username,
           long bookedID);

    std::string getDate() const;

    std::string getFlightNo() const;

    std::string getSeat() const;

    std::string getPrice() const;

    std::string getUsername() const;

    void setDate(std::string &date);

    void setFlightNo(std::string &flightNo);

    void setSeat(std::string &seat);

    void setPrice(std::string &price);

    void setUsername(std::string &username);

    void setBookedID(long bookedID);

    long generateID();

    void printTicket() const;

    void printForFlight() const;

    void printForUsername() const;
};
