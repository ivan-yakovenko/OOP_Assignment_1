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

//
std::string Airplane::getFlightNo() const {
    return this->flightNo;
}

//
//int Airplane::getSeatsPerRow() const {
//    return seatsPerRow;
//}
//
std::unordered_map<std::string, std::string> Airplane::getPriceForSeat() const {
    return this->priceForSeat;
}

//bool Airplane::getIsAvailable() const {
//    return this->isAvailable;
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


std::unordered_map<long, Ticket> Airplane::getBookedTickets() const {
    return this->bookedTickets;
}

//void Airplane::generalPrint() const {
//    std::cout << "Date: " << date << std::endl;
//    std::cout << "Flight number: " << flightNo << std::endl;
//    for (const auto &seat: priceForSeat) {
//        std::cout << "Seat: " << seat.first << " Price: " << seat.second << std::endl;
//    }
//    std::cout << priceForSeat.size() << std::endl;
//}

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


//void Airplane::viewByUsername(std::string &username) {
//    for (const auto &ticket: bookedTickets) {
//        if (ticket.second.getUsername() == username) {
//            ticket.second.printForUsername();
//        }
//    }
//}
//
//void Airplane::viewByFlightNumber(std::string &flightNo) {
//    for (const auto &ticket: bookedTickets) {
//        if (ticket.second.getFlightNo() == flightNo) {
//            ticket.second.printForFlight();
//        }
//    }
//}