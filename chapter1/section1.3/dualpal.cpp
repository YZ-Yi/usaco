/*
ID: yiyuzhe1
TASK: dualpal
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string convert(int base, long number){
    string result;

    while(number){
        result.push_back(number % base + '0');
        number /= base;
    }

    return result;
}

int main(void){
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    long n, s;

    fin >> n >> s;

    for(long i = s + 1; n; ++i){
        int count = 0;
        for(int base = 2; base <= 10; ++base){
            string result = convert(base, i);
            string rev = result;
            reverse(result.begin(), result.end());
        

            if(rev == result){
                ++count;
                if(count == 2){
                    fout << i << endl;
                    --n;

                    break;
                }
                
            }
        }
    }

    return 0;
}