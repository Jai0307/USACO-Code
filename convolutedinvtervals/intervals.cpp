#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int MX = 10e6;

void printArr(vector<long long> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }
    // cout << endl;
    
}

int main()
{
    // freopen("intervals.in", "r", stdin);
    // freopen("intervals.out", "w", stdout);
    int N, M;
    vector<vector<int>> intervals;
    cin >> N >> M;
    vector<long long> ans(2*M+1,0);
    vector<vector<int>> addedIntervals;
    int ai, bi;
    for (size_t i = 0; i < N; i++)
    {
        cin >> ai >> bi;
        vector<int> aibi = {ai, bi};
        intervals.push_back(aibi);

    }
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = i+1; j < N; j++)
        {
            // for (size_t k = intervals[i][0]+intervals[j][0]; k <= intervals[i][1]+intervals[j][1]; k++)
            // {
            //     ans[k] += 2;
            // }
            vector<int> added = {intervals[i][0]+intervals[j][0],intervals[i][1]+intervals[j][1]};
            addedIntervals.push_back(added);
        }
        
    }

    // for 
    for (size_t i = 0; i < N; i++)
    {
        for (size_t k = 2*intervals[i][0]; k <= 2*intervals[i][1]; k++)
            {
                ans[k] += 1;
            }
    }
    
    printArr(ans);
    
    

    
}