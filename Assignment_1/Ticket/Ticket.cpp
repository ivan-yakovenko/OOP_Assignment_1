#include "Ticket.h"

Ticket::Ticket() : date("EMPTY"), flightNo("EMPTY"), seat("EMPTY"), price("EMPTY"), username("EMPTY"), bookedID(0) {}

Ticket::Ticket(std::string date, std::string flightNo, std::string seat, std::string price, std::string username,
               long bookedID) : date(date), flightNo(flightNo), seat(seat), price(price), username(username), bookedID(bookedID) {}

//std::string Ticket::getDate() const {
//    return this->date;
//}
//
std::string Ticket::getFlightNo() const {
    return this->flightNo;
}
//
std::string Ticket::getSeat() const {
    return this->seat;
}

std::string Ticket::getPrice() const {
    return this->price;
}

std::string Ticket::getUsername() const {
    return this->username;
}

long Ticket::getBookedID() const {
    return this->bookedID;
}

void Ticket::setDate(std::string &date) {
    this->date = date;
}

void Ticket::setFlightNo(std::string &flightNo) {
    this->flightNo = flightNo;
}

void Ticket::setSeat(std::string &seat) {
    this->seat = seat;
}

void Ticket::setPrice(std::string &price) {
    this->price = price;
}

void Ticket::setUsername(std::string &username) {
    this->username = username;
}

void Ticket::setBookedID(long bookedID) {
    this->bookedID = bookedID;
}

long Ticket::generateID() {
    bookedID = std::rand();
    return bookedID;
}

void Ticket::printTicket() const {
    std::cout << "Flight: " << flightNo << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Seat: " << seat << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Username: " << username << std::endl;
}

void Ticket::printForFlight() const {
    std::cout << "Seat: " << seat << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << std::endl;
}

void Ticket::printForUsername() const {
    std::cout << "Flight: " << flightNo << std::endl;
    std::cout << "Date: " << date << std::endl;
    std::cout << "Seat: " << seat << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << std::endl;
}