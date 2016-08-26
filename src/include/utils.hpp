#ifndef __FRAPU_UTILS_HPP__
#define __FRAPU_UTILS_HPP__
#include "includes.hpp"

namespace frapu
{
inline bool fileExists(std::string& filename)
{
    return boost::filesystem::exists(filename);
}
}

#endif
