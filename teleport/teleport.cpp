/*
ID: jaising1
LANG: C++
TASK: teleport
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>/
using namespace std;

int N;
map<int, int> slopechg;
int main(void)
{
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    long long current_f = 0, slope_f = 0, current_y = -2000000000;

    fin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b;
        fin >> a >> b;
        current_f += abs(a - b);

        if (abs(a) > abs(a - b))
            continue;
        slopechg[b] += 2;
        if (a < b && a < 0)
        {
            slopechg[0]--;
            slopechg[2 * b]--;
        }
        if (a < b && a >= 0)
        {
            slopechg[2 * b - 2 * a]--;
            slopechg[2 * a]--;
        }
        if (a >= b && a < 0)
        {
            slopechg[2 * b - 2 * a]--;
            slopechg[2 * a]--;
        }
        if (a >= b && a >= 0)
        {
            slopechg[0]--;
            slopechg[2 * b]--;
        }
    }

    long long min_f = current_f;
    for (auto p : slopechg)
    {
        int new_y = p.first, delta_slope = p.second;
        current_f += slope_f * (new_y - current_y);
        current_y = new_y;
        slope_f += delta_slope;
        min_f = min(min_f, current_f);
    }

    fout << min_f << "\n";
    return 0;
}