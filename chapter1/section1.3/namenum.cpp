/*
ID: yiyuzhe1
TASK: namenum
LANG: C++                 
*/

// WATCH OUT FOR OVERFLOW

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

//overload operator for comparison
// string opera

int main(void){
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream dict("dict.txt");
    uint64_t number;
    vector<string> output;
    int map[256];

    fin >> number;

    //map numbers to multiple letters
    map['A'] = map['B'] = map['C'] = 2;
    map['D'] = map['E'] = map['F'] = 3;
    map['G'] = map['H'] = map['I'] = 4;
    map['J'] = map['K'] = map['L'] = 5;
    map['M'] = map['N'] = map['O'] = 6;
    map['P'] = map['R'] = map['S'] = 7;
    map['T'] = map['U'] = map['V'] = 8;
    map['W'] = map['X'] = map['Y'] = 9;

    string line;
    while(dict >> line){
        uint64_t num = 0;
        int flag = 0;

        for(int i = 0; i < line.size(); ++i){
            if(line[i] == 'Q' || line[i] == 'Z'){
                flag = 1;
                break;
            }
            num = num * 10 + map[line[i]];
        }
        if(line == "KRISTOPHER")
            cerr << num;
        if(flag)
            continue;

        if(num == number){

            output.push_back(line);
        }
    }

    if(output.empty())
        fout << "NONE" << endl;
    for(auto out : output)
        fout << out << endl;

    return 0;
}