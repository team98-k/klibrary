#include <iostream>
#include "hashtable_2.h"

namespace hashtable
{
    const std::string DATA_NULL = "$DATA_NULL";
    const std::string KEY_NULL = "$KEY_NULL";
    const int8_t KEY_FAIL = -1;

    // 키 값이 유효한지 확인.
    bool IsValid(std::string _key)
    {
        bool result = false;

        result = true;

        return result;
    }

    // 문자열의 키 값을 int16_t 형으로 반환.
    int16_t key_to_int(std::string _key)
    {
        int16_t result = 0;

        for (int i = 0; i < _key.length(); ++i)
            result = result + (i + 1) * (int16_t)_key[i];

        return result;
    }

    // 생성자
    hashtable::hashtable(uint16_t _size)
    {
        size = _size;
        count = 0;
        std::vector<std::string> _data(_size, DATA_NULL);
        std::vector<std::string> _key(_size, KEY_NULL);
        data = _data;
        key = _key;
    }

    // 이중 해싱
    int16_t hashtable::d_hashing(std::string _key, int16_t h_key, bool isload)
    {
        uint16_t d_size = static_cast<uint16_t>(size * 0.9);
        int16_t d_key;
        int16_t int_key = key_to_int(_key);

        // 2차 해싱
        // t(key) = d_table_size - (key % d_table_size)
        // d(key) = (h(key) + i * t(key)) % table_size
        int16_t t_key = d_size - (int_key % d_size);

        int i = 1;
        while (i < size + 1) {
            d_key = (h_key + i * t_key) % size;
            if ((!isload && key[d_key] == KEY_NULL) || key[d_key] == _key)
                return d_key;

            ++i;
        }

        return KEY_FAIL;
    }

    // 해싱
    int16_t hashtable::hashing(std::string _key, bool isload)
    {
        int16_t h_key = KEY_FAIL;
        int16_t int_key = key_to_int(_key);

        // 1차 해싱
        // h(key) = key % table_size
        h_key = int_key % size;
        if ((!isload && key[h_key] == KEY_NULL) || key[h_key] == _key)
            return h_key;

        // 2차 해싱
        h_key = d_hashing(_key, h_key, isload);

        return h_key;
    }

    // 데이터 저장
    void hashtable::save(std::string _data, std::string _key)
    {
        if (!IsValid(_key))
            return;
        
        int16_t h_key = hashing(_key);
        if (h_key == KEY_FAIL)
            return;

        if (key[h_key] == KEY_NULL)
            ++count;

        key[h_key] = _key;
        data[h_key] = _data;
    }

    // 데이터 불러오기
    std::string hashtable::load(std::string _key)
    {
        std::string result = "";

        if (!IsValid(_key))
            return result;
        
        int16_t h_key = hashing(_key, true);
        if (h_key == KEY_FAIL)
            return result;

        return data[h_key];
    }

    // 해시 테이블 정보 출력
    void hashtable::tablelist(bool _filter_active, uint16_t _begin, uint16_t _end)
    {
        uint16_t begin = _begin;
        uint16_t end = _end == 1000 ? size : _end;

        for (int i = begin; i < end; ++i) {
            if (!_filter_active || key[i] != KEY_NULL)
                std::cout << "table_index: " << i << ", key: " << key[i] << ", data: " << data[i] << std::endl;     
        }
    }
}