#include <iostream>
#include "ConfigReader/ConfigReader.h"
#include "CLI/CLI.h"

int main() {
    std::string filePath = "/Users/ivanyakovenko/CLionProjects/OOP_Assignment_1/Assignment_1/config/config.txt";
    CLI CLI(filePath);
    CLI.run();
}