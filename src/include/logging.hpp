#ifndef __FRAPU_LOGGING_HPP__
#define __FRAPU_LOGGING_HPP__
#include <iostream>
#include <assert.h>

namespace frapu
{

inline void WARNING(std::string message)
{
    std::clog << "\033[33m " << message << "\33[39m" << std::endl;    
}

inline void ERROR(std::string message) {
    std::cerr << "\033[31m ERROR: " << message << "\33[39m" << std::endl;
    assert(false && "");
}

inline void LOGGING(std::string message) {
    std::clog << "\033[32m " << message << "\33[39m" << std::endl;
}

/**inline void LOG(std::string message) {
    std::clog << "\033[32m " << message << "\33[39m" << std::endl;
}*/

}

#endif

