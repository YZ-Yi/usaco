/*
ID: yiyuzhe1
TASK: beads
LANG: C++                 
*/

/*
 I have to admit that I got stuck on this questioan again, 
 and took the example solution as a reference to get this
 solution. And this solution takes O(n^2), though I believe
 this question can be done in O(n), it seems really complicated.
 Luckily, the question doesn't have running time limits. So
 hopefully I can get a solution with O(n) running time one day
 :c
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void){
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    unsigned int n;
    string beads;

    fin >> n >> beads;
    beads += beads;

    unsigned int state;
    unsigned int max = 0;

    for(int i = 0; i < 2 * n; ++i){
        if(beads[i] == 'w')
            state  = 0;
        else 
            state = 1;

        int j = i + 1;
        unsigned int length = 1;
        string color;
        color.push_back(beads[i]);

        while(j < n * 2){
            if(color[0] != beads[j] && beads[j] != 'w'){
                ++state;
                color[0] = beads[j];
            }

            if(state > 2)
                break;
            
            ++length;
            ++j;
        }

        if(length > max)
            max = length;

        if(max >  n)
            max = n;
    }

    fout << max << endl;

    return 0;
}