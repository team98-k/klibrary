#ifndef hashtable_2_h
#define hashtable_2_h

#include <vector>

namespace hashtable
{
    class hashtable
    {
        uint16_t size;
        uint16_t count;
        std::vector<std::string> data;
        std::vector<std::string> key;

    public:
        hashtable(uint16_t _size = 1000);
        int16_t d_hashing(std::string _key, int16_t h_key, bool isload);
        int16_t hashing(std::string _key, bool isload = false);
        void save(std::string _data, std::string _key);
        std::string load(std::string _key);
        void tablelist(bool _filter_active = true, uint16_t _begin = 0, uint16_t _end = 1000);
    };
}

#endif