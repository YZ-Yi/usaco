/*
ID: yiyuzhe1
TASK: gift1
LANG: C++                 
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct person{
    string name;
    int money = 0;
};

int main(void){
    int n;
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    //reading total number of friends from input
    fin >> n;

    struct person friends[n];

    //reading friends' names
    for(int i = 0; i < n; ++i)
        fin >> friends[i].name;

    string giver, reciever;
    int money, num;

    //reading money and friends who recieving gifts
    for(int i = 0; i < n; ++i){
        fin >> giver >> money >> num;

        //REMEMBER CONSIDERING GIVING 0 PERSON GIFTS!!!!!!!
        for(int j = 0; j < n; ++j){
            if(friends[j].name == giver){
                if(num == 0){
                    friends[j].money += money;
                    continue;
                }
                friends[j].money = friends[j].money + money % num - money; 
            }
        }

        for(int j = 0; j < num; ++j){
            fin >> reciever;

            for(int k = 0; k < n; ++k)
                if(friends[k].name == reciever)
                    friends[k].money += (money / num);
        }
    }


    for(int i = 0; i < n; ++i)
        fout << friends[i].name << " " << friends[i].money << endl;

    return 0;
}