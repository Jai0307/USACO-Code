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



int main()
{
    // freopen("acowdemia.in", "r", stdin);
    // freopen("acowdemia.out", "w", stdout);
    int N, K, L;
    cin >> N >> K >> L;
    // cout << N << K << L;
    vector<int> citations(N);
    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        citations[i] = x;
    }

    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());
    // cout << citations[0] << " " << citations[N-1] << "\n";
    long long upper=N, lower = 0, ans = 1;
    while(lower<=upper)
    {
        int h = (upper + lower + 1)/2;
        // cout << "lower: " << lower << " upper: " << upper <<" mid:"<< h << endl;
        long long needed = 0;
        for (auto i = 0; i < h; i++)
        {
            needed += (long long) max(0, h-citations[i]);
        }

        // cout << "needed < K*L && h <= citations[h-1]+K \n" << needed << " <= ";
        // cout << K*L << " && " << h << " <= " << citations[h-1]+K << endl; 
        if(needed <= ((long long) K* (long long) L) && h <= citations[h-1]+K)
        {
            lower = h+1;
            ans = h; 

        }
        else
        {
            upper = h-1;
        }
        // cout << endl;
    }
    // cout  << upper;
    cout << ans;
    

}