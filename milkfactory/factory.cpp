/*
ID: jaising1
LANG: C++
TASK: factory
*/
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



bool canGetToAllCity(int N, map<int, vector<int>> destMappings, int node)
{
    set<int> workingCities;
    set<int> needsTesting;
    workingCities.insert(node);
    needsTesting.insert(node);
    while(needsTesting.size() != 0)
    {
       set<int>::iterator it = needsTesting.begin(); 
       set<int> newTesting;
       while(it != needsTesting.end())
       {

           for(int i = 0; i < destMappings[*it].size();i++)
           {
               if(workingCities.count(destMappings[*it][i]) == 1)
               {
                   continue;
               }
               else
               {
                   workingCities.insert(destMappings[*it][i]);
                   newTesting.insert(destMappings[*it][i]);
               }
           }
           it++;
       }
       needsTesting = newTesting;
    }
    return workingCities.size() == N;
}



FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int N;
    cin >> N;
    map<int, vector<int>> getToDest;
    set<int> allDest;
    for(int i = 1; i < N;i++)
    {
        int start, dest;
        cin >> start >> dest;
        getToDest[dest].push_back(start);
        allDest.insert(dest);
    }
    set<int>::iterator it = allDest.begin();

    int value = -1;
    while(it != allDest.end())
    {
        if(canGetToAllCity(N, getToDest, *it))
        {
            value = *it;
            break;
        }
        it++;
    }
    cout << value << endl;



    fclose(stdin);
    fclose(stdout);
}