#include "../FileHandler/FileHandler.h"

struct FileCloser {
    void operator()(FileHandler *fd) const;
};


