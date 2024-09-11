#include "Airplane.h"

Airplane::Airplane() : date("Empty"), flightNo("Empty"), priceForSeat({}), bookedSeat({}), bookedTickets({}) {}

Airplane::Airplane(std::string date, std::string flightNo,
                   std::unordered_map<std::string, std::string> priceForSeat,
                   std::unordered_map<std::string, std::string> bookedSeat, std::vector<Ticket> bookedTickets) : date(date),
                                                                              flightNo(flightNo),
                                                                              priceForSeat(priceForSeat),
                                                                              bookedSeat(bookedSeat),
                                                                              bookedTickets(bookedTickets){}

//std::string Airplane::getDate() const {
//    return date;
//}
//
//std::string Airplane::getFlightNo() const {
//    return flightNo;
//}
//
//int Airplane::getSeatsPerRow() const {
//    return seatsPerRow;
//}
//
//std::unordered_map<std::string, std::string> Airplane::getPriceForSeat() const {
//    return priceForSeat;
//}

//bool Airplane::getIsAvailable() const {
//    return isAvailable;
//}

//void Airplane::setDate(std::string &date) {
//    this->date = date;
//}
//
//void Airplane::setFlightNo(std::string &flightNo) {
//    this->flightNo = flightNo;
//}
//
//void Airplane::setSeatsPerRow(int seatsPerRo) {
//    this->seatsPerRow = seatsPerRow;
//}
//
//void Airplane::setPriceForSeat(std::unordered_map<std::string, std::string> &priceForSeat) {
//    this->priceForSeat = priceForSeat;
//}

//void Airplane::setIsAvailable(bool isAvailable) {
//    this->isAvailable = isAvailable;
//}


std::vector<Ticket> Airplane::getBookedTickets() const {
    return this->bookedTickets;
}

void Airplane::generalPrint() const {
    std::cout << "Date: " << date << std::endl;
    std::cout << "Flight number: " << flightNo << std::endl;
    for (const auto &seat: priceForSeat) {
        std::cout << "Seat: " << seat.first << " Price: " << seat.second << std::endl;
    }
    std::cout << priceForSeat.size() << std::endl;
}

void Airplane::printPlaces() const {
    for (const auto &seat: priceForSeat) {
        std::cout << "Seat: " << seat.first << " Price: " << seat.second << std::endl;
    }
}

void Airplane::check(std::string &date, std::string &flightNo) const {
//    if (this->date == date && this->flightNo == flightNo) {
//        printPlaces();
//    }
    std::cout << priceForSeat.size() << std::endl;
}

void Airplane::book(std::string &date, std::string &flightNo, std::string &seat, std::string &username) {
    if (this->date == date && this->flightNo == flightNo) {
        if (priceForSeat.contains(seat)) {
            Ticket ticket;
            ticket.setDate(date);
            ticket.setFlightNo(flightNo);
            ticket.setSeat(seat);
            ticket.setPrice(priceForSeat.at(seat));
            ticket.setUsername(username);
            ticket.setBookedID(ticket.generateID());
            bookedSeat.insert(priceForSeat.extract(seat));
            bookedTickets.emplace_back(ticket);
        }
    }
}

void Airplane::returnTicket(long bookedID) {
    for(auto iterator = bookedTickets.begin(); iterator != bookedTickets.end(); iterator++) {
        if(iterator->getBookedID() == bookedID) {
            priceForSeat.insert(bookedSeat.extract(iterator->getSeat()));
            bookedTickets.erase(iterator);
            break;
        }
        else {
            std::cerr << "No such ID" << std::endl;
        }
    }
}

void Airplane::viewByID(long bookedID) {
    for(auto iterator = bookedTickets.begin(); iterator != bookedTickets.end(); iterator++) {
        if(iterator->getBookedID() == bookedID) {
            iterator->printTicket();
            break;
        }
        else {
            std::cerr << "No such ID" << std::endl;
        }
    }
}

void Airplane::viewByUsername(std::string &username) {
    for(auto iterator = bookedTickets.begin(); iterator != bookedTickets.end(); iterator++) {
        if(iterator->getUsername() == username) {
            iterator->printTicket();
            break;
        }
        else {
            std::cerr << "No such username" << std::endl;
        }
    }
}

void Airplane::viewByFlightNumber(std::string &flightNo) {
    for(auto iterator = bookedTickets.begin(); iterator != bookedTickets.end(); iterator++) {
        if(iterator->getFlightNo() == flightNo) {
            iterator->printForFlight();
        }
        else {
            std::cerr << "No such username" << std::endl;
        }
    }
}