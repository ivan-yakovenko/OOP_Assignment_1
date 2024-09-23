#pragma once

#include <iostream>
#include <fcntl.h>
#include <unistd.h>

class FileHandler {
public:
    FileHandler();

    FileHandler(std::string &filename, int flag);

    FileHandler(const FileHandler &other) = delete;

    FileHandler operator=(const FileHandler &other) const = delete;

    FileHandler(FileHandler &&other) noexcept;

    FileHandler &operator=(FileHandler &&other) noexcept;

    explicit operator int() const;

    int getFD() const;

private:
    int fd;
};


