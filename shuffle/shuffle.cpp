/*
ID: jaising1
LANG: C++
TASK: shuffle
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

FILE *fin;
fstream fout;
int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int N;
    cin >> N;
    vector<int> shufflePos;
    vector<bool> cowPos(N, true);
    for (int i = 0; i < N; i++)
    {
        int pos;
        cin >> pos;
        shufflePos.push_back(pos);
    }

    fclose(stdin);
    fclose(stdout);
}