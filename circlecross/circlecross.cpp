/*
ID: jaising1
LANG: C++
TASK: circlecross
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

FILE *fin;
fstream fout;
int main()
{
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    int N;
    cin >> N;
    int pairsNum, curIndx = 0;
    set<int> entryExitOrder;
    map<int, int> entryExitOrderMap;

    for (int i = 0; i < 2 * N; i++)
    {
        int cow;
        cin >> cow;
        if (entryExitOrderMap.count(cow) == 1)
        {
            pairsNum += curIndx - entryExitOrderMap[cow] - 1;
        }
        else
        {
        }
        if (entryExitOrder.count(cow) == 1)
        {
            entryExitOrder.erase(cow);
            cout << "count is " << entryExitOrder.size() << " for" << cow << endl;
            pairsNum += entryExitOrder.size();
        }
        else
        {
            entryExitOrder.insert(cow);
        }
    }
    cout << pairsNum << endl;
    fclose(stdin);
    fclose(stdout);
}
