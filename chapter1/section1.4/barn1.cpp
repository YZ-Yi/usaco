/*
ID: yiyuzhe1
TASK: barn1
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

struct stall{
    int beg, end;
};

int main(void){
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int m, s, c;

    fin >> m >> s >> c;
    list<stall> stalls;
    stall st;
    vector<int> vec;
    for(int i = 0; i < c; ++i){
        int input;
        fin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    st.beg = vec[0];
    st.end = vec[0];
    stalls.push_back(st);
    for(int i = 1; i < c; ++i){
        st = stalls.back();
        if(vec[i] > st.end){
            stall new_s;
            new_s.beg = vec[i];
            new_s.end = vec[i];
            stalls.push_back(new_s);
        }
        else{
            st.end = vec[i];
            stalls.pop_back();
            stalls.push_back(st);
        }
    }


    int num;
    while(stalls.size() > m){
        // find the shortest continued empty stalls
        int length = s;
        int i = 0;
        for(auto itr = stalls.begin(); itr != stalls.end(); ++itr){
            auto itr2 = next(itr);
            if(itr2 != stalls.end()){
                int empty_stalls = (*itr2).beg - (*itr).end - 1;
                if(empty_stalls < length){
                    length = empty_stalls;
                    num = i;
                }
            }
            ++i;
        }

        // merge stalls
        auto itr = stalls.begin();
        for(i = 0; i != num; ++itr, ++i)
            ;
        auto itr2 = next(itr);
        (*itr).end = (*itr2).end;
        stalls.erase(itr2);
    }

    int total = 0;
    for(auto i : stalls){
        // cout << i.beg << " " << i.end << endl;
        total += i.end - i.beg + 1;
    }
    fout << total << endl;

    return 0;
}