#ifndef klibrary_h
#define klibrary_h

#include <vector>

namespace hashtable
{
    const std::string KEY_NULL = "$KEY_NULL";
    const int8_t KEY_FAIL = -1;

    bool IsValid(std::string _key);
    int16_t key_to_int(std::string _key);

    template <typename T>
    class hashtable
    {
        uint16_t size;
        uint16_t count;
        std::vector<T> data;
        std::vector<std::string> key;

    public:
        int16_t d_hashing(std::string _key, int16_t h_key, bool isload);
        int16_t hashing(std::string _key, bool isload = false);
        hashtable(uint16_t _size = 1000);
        void save(T _data, std::string _key);
        T* load(std::string _key);
        void tablelist(bool _filter_active = true, uint16_t _begin = 0, uint16_t _end = 1000);
    };
}

#endif