#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
#define ll long long
const int MX = 10e6;

ll feedCows(vector<ll> &cows, int N)
{
    ll actions = 0;
    for (int i = 1; i < N-1; i++)
    {
        if(cows[i]>cows[i-1])
        {
            int dif = cows[i]-cows[i-1];
            cows[i] -=dif;
            cows[i+1] -= dif;
            actions += dif*2;
        }
    }
    return actions;
    
}



int main()
{
    // freopen("drought.in", "r", stdin);
    // freopen("drought.out", "w", stdout);
    int N, T;
    cin >> T;
    // cout << "T : " << T << endl;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        // cout  << "i: " << i << " N: " << N << "\n";
        
        
        
        vector<ll> cowVec(N);
        
        for (int j = 0; j < N; j++)
        {
            cin >> cowVec[j];
        }
        
        if(N == 1)
            {cout << 0 << "\n"; continue;}
        ll actions = feedCows(cowVec, N);
        
        if(cowVec[N-1]>cowVec[N-2])
            {cout << -1 << "\n"; continue;}
        
        reverse(cowVec.begin(),cowVec.end());
        actions += feedCows(cowVec, N);
        auto mn = min_element(cowVec.begin(),cowVec.end());
        if(cowVec[N-1]!=cowVec[N-2] || *mn < 0)
            {cout << -1 << "\n"; continue;}
        
        cout << actions << "\n";
        

        
    }
    
}


