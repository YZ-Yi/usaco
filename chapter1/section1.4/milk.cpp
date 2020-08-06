/*
ID: yiyuzhe1
TASK: milk
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct farm{
    int p, a;

    bool operator< (farm f){
        return p < f.p;
    }
};

int main(void){
    ifstream fin("milk.in");
    ofstream fout("milk.out");
    int n, m;

    // read data from the input file
    fin >> n >> m;
    vector<farm> f(m);

    for(int i = 0; i < m; ++i)
        fin >> f[i].p >> f[i].a;

    sort(f.begin(), f.end());

    int price = 0;
    int i = 0;

    while(n){
        if(n >= f[i].a){
            n -= f[i].a;
            price += f[i].a * f[i].p;
        }
        else{
            price += f[i].p * n;
            n = 0;
        }
        ++i;
    }

    fout << price << endl;

    return 0;
}