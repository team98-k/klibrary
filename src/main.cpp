#include <iostream>
#include "hashtable.h"
#include "Point.h"
#include "hashtable_2.h"
using namespace std;

template <class T1, class T2>
void ShowData(double num)
{
    cout<<(T1)num<<", "<<(T2)num<<endl;
}

int main()
{
    ShowData<char, double>(65);

    Array<Point<int>> orr1(3);
    orr1[0]=Point<int>(3, 4);
    orr1[1]=Point<int>(5, 6);
    orr1[2]=Point<int>(7, 8);

    for(int i=0; i<orr1.GetArrLen(); i++)
        orr1[i].ShowPosition();

    return 0;
}