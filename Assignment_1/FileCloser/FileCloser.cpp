#include "FileCloser.h"

void FileCloser::operator()(FileHandler *fd) const {
    if (int(*fd) && int(*fd) != -1) {
        close(int(*fd));
        delete fd;
    }
}