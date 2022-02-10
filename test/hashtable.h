#ifndef __HASH_TABLE_H_
#define __HASH_TABLE_H_

#include<iostream>
#include<cstdlib>
using namespace std;

template<typename T>
class Array
{
private:
    T * arr;
    int arrlen;

    Array(const Array& arr){}
    Array& operator=(const Array& arr){}
public:
    Array(int  len);
    T& operator[] (int idx);
    T operator[] (int idx) const;
    int GetArrLen() const;
    ~Array();
};

template<typename T>
Array<T>::Array(int len): arrlen(len)
{
    arr=new T[len];
}

template<typename T>
T& Array<T>::operator[](int idx)
{
    if(idx<0 || idx>=arrlen)
    {
        cout<<"Array index out of bound exception"<<endl;
        exit(1);
    }
    return arr[idx];
}

template<typename T>
int Array<T>::GetArrLen() const
{
    return arrlen;
}

template<typename T>
Array<T>::~Array()
{
    delete[]arr;
}

#endif