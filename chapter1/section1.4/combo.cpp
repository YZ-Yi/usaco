/*
ID: yiyuzhe1
TASK: combo
LANG: C++                 
*/

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

bool valid(int dial, int number){
    if(num[dial - 2] == number || num[dial - 1] == number || num[dial] == number
        || num[dial + 1] == number || num[dial + 2] == number)
        return true;
    return false;
}

int main(void){
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    int n;
    vector<int> farmer(3), master(3);

    fin >> n;
    for(int i = 0; i < 3; ++i)
        fin >> farmer[i];
    for(int i = 0; i < 3; ++i)
        fin >> master[i];
    for(int i = 1; i <= n; ++i)
        num.push_back(i);
    num.insert(num.end(), num.begin(), num.end());
    
    // test for all possible resluts
    int count = 0;
    for(int i = 2; i < n + 2; ++i)
        for(int j = 2; j < n + 2; ++j)
            for(int k = 2; k < n + 2; ++k){
                // test if it can open farmer's lock
               if(valid(i, farmer[0]) && valid(j, farmer[1]) && valid(k, farmer[2])){
                    ++count;
                    continue;
               }
                // test if it can open matser lock
                if(valid(i, master[0]) && valid(j, master[1]) && valid(k, master[2]))
                    ++count;
            }

    fout << count << endl;

    return 0;
}