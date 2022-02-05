#ifndef hashtable_2_h
#define hashtable_2_h

#include <vector>

namespace hashtable
{
    class hashtable
    {
        uint16_t size;
        std::vector<std::string> data;
        std::vector<std::string> key;
        int count;

    public:
        hashtable(uint16_t _size = 1000);
        int hashing(std::string _key, bool isload = false);
        int d_hashing(std::string _key, int h_key, bool isload);
        void save(std::string _data, std::string _key);
        std::string load(std::string _key);
    };

    template <typename T>
    std::vector<T> data;

    template <typename T>
    void Add(T _data);
}

#include "hashtable_2.hpp"

#endif