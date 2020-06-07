/*
ID: yiyuzhe1
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>

using namespace std;

unsigned int isLeapYear(unsigned int year){
    if(year % 400 == 0 ||(year % 100 != 0 && year % 4 == 0))
        return 1;
    
    return 0;
}

int main(void){
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    unsigned int n;
    unsigned int total = 0, leap = 0;

    unsigned int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                                 {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };
    unsigned int week[7] {0};

    fin >> n;

    for(int i = 0; i < n; ++i){
        leap = isLeapYear(1900 + i);

        for(int j = 0; j < 12; ++j){
            ++week[(total + 14) % 7];
            total += month[leap][j];
        }
    }

    for(int i = 0; i < 6; ++i)
        fout << week[i] << " ";

    fout << week[6] << endl;

    return 0;
}