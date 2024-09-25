#include "CLI.h"

CLI::CLI(std::string &filePath) : filePath(filePath) {
    airplanes = configReader.getAirplanesInfo(filePath);
}

void CLI::checkPlaces(std::string &date, std::string &flightNo) {
    bool checked = false;
    for (auto &airplane: airplanes) {
        if (airplane.getDate() == date && airplane.getFlightNo() == flightNo) {
            airplane.check(date, flightNo);
            checked = true;
            break;
        }
    }
    if (!checked) {
        std::cerr << "No such flight information" << std::endl;
    }
}

void CLI::bookSeat(std::string &date, std::string &flightNo, std::string &seat, std::string &username) {
    bool booked = false;
    for (auto &airplane: airplanes) {
        if (airplane.getDate() == date && airplane.getFlightNo() == flightNo &&
            airplane.getPriceForSeat().contains(seat)) {
            airplane.book(date, flightNo, seat, username);
            booked = true;
            break;
        }
    }
    if (!booked) {
        std::cerr << "No such booking information" << std::endl;
    }
}

void CLI::returnTicket(long bookedID) {
    bool returned = false;
    for (auto &airplane: airplanes) {
        if (airplane.getBookedTickets().contains(bookedID)) {
            airplane.returnTicket(bookedID);
            returned = true;
            break;
        }
    }
    if (!returned) {
        std::cerr << "No such ID" << std::endl;
    }
}

void CLI::viewID(long bookedID) {
    bool viewed = false;
    for (auto &airplane: airplanes) {
        if (airplane.getBookedTickets().contains(bookedID)) {
            airplane.viewByID(bookedID);
            viewed = true;
            break;
        }
    }
    if (!viewed) {
        std::cerr << "No such ID to view" << std::endl;
    }
}

void CLI::viewUsername(std::string &username) {
    bool viewed = false;
    for (auto &airplane: airplanes) {
        for (const auto &ticket: airplane.getBookedTickets()) {
            if (ticket.second.getUsername() == username) {
                ticket.second.printForUsername();
                viewed = true;
            }
        }
    }
    if (!viewed) {
        std::cerr << "No such username" << std::endl;
    }
}

void CLI::viewFlight(std::string &flightNo, std::string &date) {
    bool viewed = false;
    for (auto &airplane: airplanes) {
        for (const auto &ticket: airplane.getBookedTickets()) {
            if (ticket.second.getFlightNo() == flightNo && ticket.second.getDate() == date) {
                ticket.second.printForFlight();
                viewed = true;
            }
        }
        if (viewed) {
            break;
        }
    }
    if (!viewed) {
        std::cerr << "No information about such flight number" << std::endl;
    }
}

bool CLI::checkIfId(std::string &parameter) {
    for (char &charachter: parameter) {
        if (isdigit(charachter)) {
            return true;
        }
    }
    return false;
}

bool CLI::validCommand(std::string &command) {
    if (command != "check" && command != "book" && command != "return" && command != "view") {
        std::cerr << "Wrong command, try again" << std::endl;
        return false;
    }
    return true;
}

void CLI::run() {
    while (true) {
        std::string commandLine, command;
        std::getline(std::cin, commandLine);
        std::istringstream tokens(commandLine);
        tokens >> command;
        if (!validCommand(command)) {
            continue;
        }
        if (command == "check") {
            std::string date, flightNo;
            tokens >> date >> flightNo;
            checkPlaces(date, flightNo);
        }
        if (command == "book") {
            std::string date, flightNo, seat, username;
            tokens >> date >> flightNo >> seat >> username;
            bookSeat(date, flightNo, seat, username);
        }
        if (command == "return") {
            long bookedID;
            tokens >> bookedID;
            returnTicket(bookedID);
        }
        if (command == "view") {
            std::string parameter;
            tokens >> parameter;
            if (checkIfId(parameter)) {
                long bookedID = std::stol(parameter);
                viewID(bookedID);
            } else {
                if (parameter != "username" && parameter != "flight") {
                    std::cerr << "Wrong parameter, try again" << std::endl;
                }
                if (parameter == "username") {
                    std::string username;
                    tokens >> username;
                    viewUsername(username);
                }
                if (parameter == "flight") {
                    std::string flightNo, date;
                    tokens >> flightNo >> date;
                    viewFlight(flightNo, date);
                }

            }
        }
    }
}

