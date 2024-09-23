#include "Airplane.h"

Airplane::Airplane() : date("Empty"), flightNo("Empty"), priceForSeat({}), bookedSeat({}), bookedTickets({}) {}

Airplane::Airplane(std::string date, std::string flightNo,
                   std::unordered_map<std::string, std::string> priceForSeat,
                   std::unordered_map<std::string, std::string> bookedSeat,
                   std::unordered_map<long, Ticket> bookedTickets) : date(date),
                                                                     flightNo(flightNo),
                                                                     priceForSeat(priceForSeat),
                                                                     bookedSeat(bookedSeat),
                                                                     bookedTickets(bookedTickets) {}

std::string Airplane::getDate() const {
    return this->date;
}


std::string Airplane::getFlightNo() const {
    return this->flightNo;
}

std::unordered_map<std::string, std::string> Airplane::getPriceForSeat() const {
    return this->priceForSeat;
}

std::unordered_map<long, Ticket> Airplane::getBookedTickets() const {
    return this->bookedTickets;
}

void Airplane::printPlaces() const {
    for (const auto &seat: priceForSeat) {
        std::cout << "Seat: " << seat.first << " Price: " << seat.second << std::endl;
    }
    std::cout << "PLaces left: " << priceForSeat.size() << std::endl;
}

void Airplane::check(std::string &date, std::string &flightNo) const {
    if (this->date == date && this->flightNo == flightNo) {
        printPlaces();
    }
}

void Airplane::book(std::string &date, std::string &flightNo, std::string &seat, std::string &username) {
    Ticket ticket;
    long bookedID = ticket.generateID();
    ticket.setDate(date);
    ticket.setFlightNo(flightNo);
    ticket.setSeat(seat);
    ticket.setPrice(priceForSeat.at(seat));
    ticket.setUsername(username);
    ticket.setBookedID(bookedID);
    std::cout << "Confirmed with ID: " << bookedID << std::endl;
    bookedSeat.insert(priceForSeat.extract(seat));
    bookedTickets[bookedID] = ticket;
}

void Airplane::returnTicket(long bookedID) {
    Ticket &ticket = bookedTickets.at(bookedID);
    std::cout << "Confirmed " << ticket.getPrice() << " refund for " << ticket.getUsername() << std::endl;
    priceForSeat.insert(bookedSeat.extract(ticket.getSeat()));
    bookedTickets.erase(bookedID);
}


void Airplane::viewByID(long bookedID) {
    Ticket &ticket = bookedTickets.at(bookedID);
    ticket.printTicket();
}