#include "ConfigReader.h"

std::vector<Airplane> ConfigReader::getAirplanesInfo(std::string& filename) {
    std::ifstream fin(filename);
    std::string line;
    std::vector<Airplane> airplanes;


    while(std::getline(fin, line)) {
        std::istringstream tokens(line);
        std::string date, flightNo, price;
        int seatsPerRow;
        int startRow, endRow;
        tokens >> date >> flightNo >> seatsPerRow;

        if(seatsPerRow > 26) {
            std::cerr << "Too many seats per row" << std::endl;
            line.clear();
            line.shrink_to_fit();
            continue;
        }
        else {
            std::unordered_map<std::string, std::string> priceForSeat;
            while(tokens >> startRow >> endRow >> price) {
                seatsGenerator(seatsPerRow, startRow, abs(endRow), price, priceForSeat);
            }
            Airplane airplane(date, flightNo, priceForSeat, {}, {});
            airplanes.push_back(airplane);
        }
    }
    return airplanes;
}

void ConfigReader::seatsGenerator(int seatsPerRow, int startRow, int endRow, std::string &price, std::unordered_map<std::string, std::string>& priceForSeat) {
    for (int i = startRow; i <= endRow; i++) {
        for (char j = 'A'; j < 'A' + seatsPerRow; j++) {
            priceForSeat[std::to_string(i) + j] = price;
        }
    }
}