#ifndef hashtable_2_h
#define hashtable_2_h

#include <vector>

namespace hashtable
{
    class hashtable
    {
        uint16_t size;
        std::vector<std::string> data;
    public:
        hashtable(uint16_t _size = 1000);
        void hashing();
    };
}

#endif