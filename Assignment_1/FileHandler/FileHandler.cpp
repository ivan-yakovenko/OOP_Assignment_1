#include "FileHandler.h"

FileHandler::FileHandler() : fd(-1) {}

FileHandler::FileHandler(std::string &filename, int flag) {
    fd = open(filename.c_str(), flag);
    if (fd == -1) {
        throw std::runtime_error("Error, can not open the file");
    }
}

FileHandler::FileHandler(FileHandler &&other) noexcept: fd(other.fd) {
    other.fd = -1;
}

FileHandler &FileHandler::operator=(FileHandler &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    if (this->fd != -1) {
        close(this->fd);
    }
    this->fd = other.fd;
    other.fd = -1;
    return *this;
}

FileHandler::operator int() const {
    return this->fd;
}

int FileHandler::getFD() const {
    return this->fd;
}