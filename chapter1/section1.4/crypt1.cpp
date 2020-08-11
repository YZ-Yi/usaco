/*
ID: yiyuzhe1
TASK: crypt1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void){
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    int n;

    fin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; ++i){
        fin >> num[i];
    }

    // get all possible multipliers and partial products
    unordered_map<int, int> pars;
    vector<int> multipliers;
    for(int i = 0, m = 0; i < n; ++i){
        if(!num[i])
            continue;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                int number = num[i] * 100 + num[j] * 10 + num[k];
                multipliers.push_back(number);
                pars[number] = m++;
            }
        }
    }

    // get all possibe multiplicands 
    vector<int> multiplicands;
    for(int i = 0; i < n; ++i){
        if(!num[i])
            continue;
        for(int j = 0; j < n; ++j){
            int number = num[i] * 10 + num[j];
            multiplicands.push_back(number);
        }    
    }

    // get all possible products
    unordered_map<int, int> products;
    for(int i = 0, m = 0; i < n; ++i){
        if(!num[i])
            continue;
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                for(int l = 0; l < n; ++l){
                    int number = num[i] * 1000 + num[j] * 100 + num[k] * 10 + num[l];
                    products[number] = m++;
                }
            }
        }
    }
    
    // test for all possible solutions
    int count = 0;
    for(int i = 0; i < multipliers.size(); ++i){
        for(int j = 0; j < multiplicands.size(); ++j){
            int result = multipliers[i] * multiplicands[j];
            if(products.find(result) != products.end()){      
                              
                // get the first partial product
                int first = multipliers[i] * (multiplicands[j] % 10);

                if(pars.find(first) != pars.end()){
                    // get the second partial product
                    int second = multipliers[i] * (multiplicands[j] / 10);
                    if(pars.find(second) != pars.end())
                        ++count;
                }
            }
        }
    }

    fout << count << endl;;

    return 0;
}