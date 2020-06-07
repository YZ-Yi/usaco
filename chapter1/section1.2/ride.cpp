/*
ID: yiyuzhe1
TASK: ride
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void){
    string ufo, group;
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    unsigned ufoNum = 1, groupNum = 1;

    //reading strings from input file
    fin >> ufo;
    fin >> group;

    for(int i = 0; i < ufo.size(); ++i)
        ufoNum *= (ufo[i] - 'A' + 1);
    
    for(int i = 0; i < group.size(); ++i)
        groupNum *= (group[i] - 'A' + 1);

    ufoNum = ufoNum % 47;
    groupNum = groupNum % 47;

    if(groupNum == ufoNum)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;

    return 0;
}