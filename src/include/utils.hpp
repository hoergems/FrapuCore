#ifndef __FRAPU_UTILS_HPP__
#define __FRAPU_UTILS_HPP__
#include "includes.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace frapu
{
inline bool fileExists(std::string& filename)
{
    return boost::filesystem::exists(filename);
}

template<class T>
inline void printVector(std::vector<T> vec, std::string str)
{
    cout << str << ": ";
    for (auto & k : vec) {
        cout << k << ", ";
    }
    cout << endl;
}

template<class T>
inline void hash_combine(std::size_t& seed, T const& v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

}

#endif
