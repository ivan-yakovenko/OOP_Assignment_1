#include "ConfigReader.h"

void ConfigReader::readLine(char *buffer, ssize_t returnValue, std::string &line, std::vector<Airplane> &airplanes) {
    for (ssize_t i = 0; i < returnValue; i++) {
        if (buffer[i] == '\n') {
            tokenizeLine(line, airplanes);
            line.clear();
            line.shrink_to_fit();
        } else {
            line += buffer[i];
        }
    }
}

void ConfigReader::tokenizeLine(std::string &line, std::vector<Airplane> &airplanes) {
    std::istringstream tokens(line);
    std::string date, flightNo, price;
    int seatsPerRow;
    int startRow, endRow;
    tokens >> date >> flightNo >> seatsPerRow;

    if (seatsPerRow > 26) {
        line.clear();
        line.shrink_to_fit();
        return;
    } else {
        std::unordered_map<std::string, std::string> priceForSeat;
        while (tokens >> startRow >> endRow >> price) {
            seatsGenerator(seatsPerRow, startRow, abs(endRow), price, priceForSeat);
        }
        Airplane airplane(date, flightNo, priceForSeat, {}, {});
        airplanes.push_back(airplane);
    }
}

std::vector<Airplane> ConfigReader::getAirplanesInfo(std::string &filename) {
    filePtr fileHandler(new FileHandler(filename, O_RDONLY));
    std::string line;
    std::vector<Airplane> airplanes;

    size_t bufferSize = 256;
    char buffer[bufferSize];

    ssize_t returnValue;

    while ((returnValue = read(fileHandler->getFD(), buffer, bufferSize)) > 0) {
        readLine(buffer, returnValue, line, airplanes);
    }

    if (!line.empty()) {
        tokenizeLine(line, airplanes);
        line.clear();
        line.shrink_to_fit();
    }

    if (returnValue == -1) {
        std::cerr << "Error occurred while reading the file" << std::endl;
    }

    return airplanes;
}

void ConfigReader::seatsGenerator(int seatsPerRow, int startRow, int endRow, std::string &price,
                                  std::unordered_map<std::string, std::string> &priceForSeat) {
    for (int i = startRow; i <= endRow; i++) {
        for (char j = 'A'; j < 'A' + seatsPerRow; j++) {
            priceForSeat[std::to_string(i) + j] = price;
        }
    }
}