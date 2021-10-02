/*
ID: jaising1
LANG: C++
TASK: outofplace
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int findOutOfPlace(vector<int> cows)
{
    vector<int> sCows =  cows;
    sort(sCows.begin(),sCows.end());
    
    
}


FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    fclose(stdin);
    fclose(stdout);
}