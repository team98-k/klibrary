#include <iostream>
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

    // Start of (std::string) 해시테이블
    string string_A = "stringA";
    string string_B = "stringB";

    hashtable::hashtable table(100); // 크기 '100' 만큼을 가진 해시테이블 생성
    
    table.save(string_A, "number1"); // 문자열 string_A를 키 값 "number1" 으로 해시테이블에 저장.
    table.save(string_B, "number2"); // 문자열 string_B를 키 값 "number2" 으로 해시테이블에 저장.

    cout << table.load("number1") << endl; // 키 값 "number1" 으로 해시테이블에서 저장된 데이터를 가져 옴.

    table.tablelist(); // 해시테이블에 저장된 모든 정보 출력.
    // End of (std::string) 해시테이블

    return 0;
}