/*
ID: yiyuzhe1
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

struct farmer{
    unsigned int beg, end;
};

bool sortByBegining(struct farmer farmer1, struct farmer farmer2){
    return (farmer1.beg < farmer2.beg);
}

int main(void){
    string inPath = "milk2.in";
    string outPath = "milk2.out";
    ifstream inFile(inPath);
    ofstream outFile(outPath);

    unsigned int n;
    inFile >> n;
    int inter1 = 0;                         //inter1 - at least one cow was milked
    int inter2 = 0;                         //inter2 - no cows were being milked
    struct farmer farmers[n];

    //reading from input
    for(int i = 0; i < n; ++i){
        inFile >> farmers[i].beg;       
        inFile >> farmers[i].end;
    }

    //sort farmer by the time they begin to milk
    sort(farmers, farmers + n, sortByBegining);

    inter1 = farmers[0]. end - farmers[0].beg;
    unsigned int curBeg = farmers[0].beg;
    unsigned int curEnd = farmers[0].end;

    for(int i = 1; i < n; ++i){
        if(farmers[i].beg <= curEnd){
            if(farmers[i].end > curEnd)
                curEnd = farmers[i].end;
        }
        else{
            if(curEnd - curBeg > inter1)
                inter1 = curEnd - curBeg;
            
            if(farmers[i].beg - curEnd > inter2)
                inter2 = farmers[i].beg - curEnd;

            curBeg = farmers[i].beg;
            curEnd = farmers[i].end;
        }
        
        if(i == n -1)
            if(curEnd - curBeg > inter1)
                inter1 = curEnd - curEnd;
    }

    outFile << inter1 << " " << inter2 << endl;

    return 0;
}