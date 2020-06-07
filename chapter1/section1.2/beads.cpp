/*
ID: yiyuzhe1
TASK: friday
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    unsigned int n, curPos, nextPos;
    string beads;

    fin >> n >> beads;
    beads += beads;
    
    //find the first not white bead
    string curBeads;
    for(int i = 0; i < n; ++i)
        if(beads[i] != 'w'){
            curBeads[0] = beadds[i];
            curPos = i;
        }

    //if all beads are white
    if(curBeads[0] != 'r' && curBeads[0] != 'b'){
        fout << n;

        return 0;
    }

    unsigned int max = 0;

    for(int i = 0; i < 2 * n; ++i){
        
    }
}