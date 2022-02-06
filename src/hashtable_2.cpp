#include <iostream>
#include <cctype>
#include "hashtable_2.h"

namespace hashtable
{
    // 키 값이 유효한지 확인.
    bool IsValid(std::string _key)
    {
        uint16_t count = 0, max = _key.length();
    
        for (const auto str : _key) {
            if (isalpha(str) || isnumber(str))
                ++count;
        }

        return count == max ? true : false;
    }

    // 문자열의 키 값을 int16_t 형으로 반환.
    int16_t key_to_int(std::string _key)
    {
        int16_t result = 0;

        for (int i = 0; i < _key.length(); ++i)
            result = result + (i + 1) * (int16_t)_key[i];

        return result;
    }
}