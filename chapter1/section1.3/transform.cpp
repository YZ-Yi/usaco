/*
ID: yiyuzhe1
TASK: transform
LANG: C++                 
*/

#include <iostream>
#include <fstream>

using namespace std;

bool comparePatterns(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(pattern1[i][j] != pattern2[i][j])
                return false;
    
    return true;
}

void rotate90(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern2[j][n - i - 1] = pattern1[i][j];

    return ;
}


void rotate180(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    rotate90(pattern1, pattern2, n);
    char pattern3[10][10];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern3[i][j] = pattern2[i][j];

    rotate90(pattern3, pattern2, n);

    return ;
}

void rotate270(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    rotate90(pattern1, pattern2, n);
    char pattern3[10][10];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern3[i][j] = pattern2[i][j];

    rotate180(pattern3, pattern2, n);

    return ;
}

void reflection(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern2[i][j] = pattern1[i][n - j - 1];

    return ;
}

void combination1(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    reflection(pattern1, pattern2, n);
    char pattern3[10][10];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern3[i][j] = pattern2[i][j];

    rotate90(pattern3, pattern2, n);

    return ;
}

void combination2(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    reflection(pattern1, pattern2, n);
    char pattern3[10][10];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern3[i][j] = pattern2[i][j];

    rotate180(pattern3, pattern2, n);

    return ;
}

void combination3(char pattern1[10][10], char pattern2[10][10], unsigned int n){
    reflection(pattern1, pattern2, n);
    char pattern3[10][10];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            pattern3[i][j] = pattern2[i][j];

    rotate270(pattern3, pattern2, n);

    return ;
}

int main(void){
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    unsigned int n;
    char original[10][10], newP[10][10], pattern[10][10];

    fin >> n;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> original[i][j];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            fin >> newP[i][j];


    rotate90(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 1 << endl;

        return 0;
    }

    rotate180(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 2 << endl;

        return 0;
    }

    rotate270(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 3 << endl;

        return 0;
    }

    reflection(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 4 << endl;

        return 0;
    }

    combination1(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 5 << endl;

        return 0;
    }

    combination2(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 5 << endl;

        return 0;
    }

    combination3(original, pattern, n);
    if(comparePatterns(newP, pattern, n)){
        fout << 5 << endl;

        return 0;
    }
    
    if(comparePatterns(original, newP, n)){
        fout << 6 << endl;
        
        return 0;
    }

    fout << 7 << endl;
}