#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>   
using namespace std;

const int MX = 10e6;


void printArr(vector<int> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
     
}

int main()
{
    // freopen("aircownditioning.in", "r", stdin);
    // freopen("aircownditioning.out", "w", stdout);
    int N, N1;
    cin >> N1;
    N=N1;
    // cout << N << endl;
    vector<int> difs(N) ;
    for (int i = 0; i < N; i++)
    {
        cin >> difs[i];
    }
    // printArr(difs);
    for (int i = 0; i < N; i++)
    {
        int ti;
        cin >> ti;
        difs[i]-=ti;
    }
    // printArr(difs);
    int ans = 0;
    while(difs.size() !=0)
    {
        if(difs[N-1] == 0)
        {
            difs.pop_back();
            N--;
            continue;
        }
        // printArr(difs);
        bool positive = difs[N-1] > 0;
        int change = 1;
        int d = abs(difs[N-1]);
        while(change < N)
        {
            if(difs[N-1-change]==0)
                break;
            if((difs[N-1-change] > 0) != positive)
                break;
            d= min(d,abs(difs[N-1-change]));
            change++;

        }
        ans += d;
        for (size_t i = 0; i < change; i++)
        {
            if(positive)
                difs[N-1-i] -= d;
            else
                difs[N-1-i] += d;
        }
        // printArr(difs);

    }
    cout << ans << "\n";

}   