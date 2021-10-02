/*
ID: jaising1
LANG: C++
TASK: speeding
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
int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M;
    cin >> N;
    cin >> M;
    vector<int> speedLimits, bSpeed;

    for(int i = 0; i < N;i++)
    {
        int length, speed;
        cin >> length >> speed;
        for(int i = 0; i < length;i++)
        {
            speedLimits.push_back(speed);
        }
    }
    for(int i = 0; i < M;i++)
    {
        int length, speed;
        cin >> length >> speed;
        for(int i = 0; i < length;i++)
        {
            bSpeed.push_back(speed);
        }
    }
    int maxOver = 0;
    for(int i = 0; i < 100;i++)
    {
        if(bSpeed[i]>speedLimits[i])
        {
            if(maxOver < bSpeed[i]-speedLimits[i])
            {
                maxOver = bSpeed[i]-speedLimits[i];
            }
        }
    }

    cout << maxOver << endl;
    fclose(stdin);
    fclose(stdout);
}