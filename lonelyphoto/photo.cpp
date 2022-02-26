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

int solve(vector<int> curBreed, vector<int> other)
{
    //case 1 H0H1G0G1
    if(other[1] < curBreed[0])
    {
        // cout << "case: 1" << endl;
        return other[1] - other[0];
    }
    //case 2 H0G0H1G1
    else if(other[0] < curBreed[0] && curBreed[0] < other[1]){
        // cout << "case: 2" << endl;
        return curBreed[0] - other[0];}
    //case 3 and last case G0H0H1G1
    else{
        // cout << "case 3:" << endl;
        return other[0] - curBreed[0];}
}


int main()
{
    // freopen("photo.in", "r", stdin);
    // freopen("photo.out", "w", stdout);
    string cows;
    int N;
    cin >> N;
    cin >> cows;
    long long total = 0;
    vector<int> gvec = {-1, -1};
    vector<int> hvec = {-1, -1};
    for (size_t i = 0; i < N; i++)
    {
        if(i>1)
        {   
            if(cows[i] == 'H')
            {
                hvec[0] = hvec[1];
                hvec[1] = i;
                int value = solve(hvec, gvec);
                total += value;
            }
            else
            {
                gvec[0] = gvec[1];
                gvec[1] = i;
                int value = solve(gvec, hvec);
                // if(value == 0)
                    
                total += value;
            }
        }
    }
    cout << total << "\n";
    
    

}