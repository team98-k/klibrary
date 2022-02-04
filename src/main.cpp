#include <iostream>
using namespace std;

template <class T1, class T2>
void ShowData(double num)
{
    cout<<(T1)num<<", "<<(T2)num<<endl;
}

int main()
{
    ShowData<char, double>(65);
    return 0;
}