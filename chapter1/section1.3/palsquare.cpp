/*
ID: yiyuzhe1
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// map numbers to numbers and characters
char map[20];

string convert(int base, int number){
    string result;

    while(number){
        result.push_back(map[number % base]);
        number /= base;
    }

    return result;
}

int main(void){
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int base;

    fin >> base;

    // initialize map
    char c = '0';
    for(int i = 0; i < 10; ++i)
        map[i] = c + i;
    c = 'A';
    for(int i = 10; i < 20; ++i)
        map[i] = c + i - 10;

    for(int i = 1; i <= 300; ++i){
        int square = i * i;
        string out = convert(base, square);
        string rev = out;
        reverse(out.begin(), out.end());
        string num = convert(base, i);
        reverse(num.begin(), num.end());

        if(out == rev)
            fout << num << " " << out << endl;
    }

    return 0;
}