/*
ID: jaising1
LANG: C++
TASK: mountains
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
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    vector<vector<int>> coords;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> coord;
        int x, y;
        cin >> x >> y;
        coord.push_back(x);
        coord.push_back(y);
        coords.push_back(coord);
    }

    fclose(stdin);
    fclose(stdout);
}