/*
ID: jaising1
LANG: C++
TASK: tracing
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    int N,T;
    string healthy;
    vector<vector<int>> interactions;
    int K;
    cin >> N >> T;
    cin >> healthy;
    for(int i =0;i<T;i++)
    {
        int time,cow1,cow2;
        cin>> time >> cow1 >> cow2;
        vector<int> interaction = {time, cow1, cow2};
        interactions.push_back(interaction);
    }
    sort(interactions.begin(),interactions.end());u

    fclose(stdin);
    fclose(stdout);
}