/*
ID: jaising1
LANG: C++
TASK: livestock
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;



int position(string c, vector<string> cows)
{
  for (int i=0; i<8; i++)
    if (cows[i]==c) return i;
  return -1;
}

bool works(vector<string> cows, vector<string> aset, vector<string> bset)
{
    for(int i = 0; i < aset.size();i++)
    {
        if(abs(position(aset[i], cows) - position(bset[i], cows))!= 1)
        {
            return false;
        }
        
    }
    return true;
}

#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows, AinPair, BinPair;
    int N;
    cin >> N;
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");
    string c1,c2,words;
    for(int i=0; i<N; i++){
        cin >> c1 >> words >> words >> words >> words >> c2;
        AinPair.push_back(c1);
        BinPair.push_back(c2);

    }
    do {
        if(works(cows,AinPair,BinPair))
        {
            for(int i=0; i<cows.size();i++)
            {
                cout << cows[i] << endl;
            }
            break;
        }
    } while (std::next_permutation(cows.begin(), cows.end()));

    fclose(stdin);
    fclose(stdout);
}