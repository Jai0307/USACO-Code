/*
ID: jaising1
LANG: C++
TASK: evolution
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

bool checkOverlap(string s1, string s2, map<string, set<int>> traits)
{
    set<int> s1Groups = traits[s1];
    set<int> s2Groups = traits[s2];
    set<int> together = s1Groups;
    together.insert(s2Groups.begin(),s2Groups.end());




    if(s1Groups.size() + s2Groups.size() == together.size())
    {
        return false;
    }
    else if(together.size() == s1Groups.size() || together.size() == s2Groups.size())
    {
        return false;
    }
    else
    {
        return true;
    }
}



FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    int N;
    cin >> N;
    bool works = true;

    map<string, set<int>> traits;
    set<string> characteristics;
    set<set<string>> possibleDupes;
    for(int i = 0; i < N;i++)
    {
        int M;
        cin >> M;
        string s;
        set<string> charInGroup;
        for(int j = 0; j < M;j++)
        {
            cin >> s;
            characteristics.insert(s);
            traits[s].insert(i);
            charInGroup.insert(s);
        }
        if(possibleDupes.count(charInGroup) == 1)
        {
            works = false;
        }
        else
        {
            possibleDupes.insert(charInGroup);
        }
    }
    set<string>::iterator it = characteristics.begin();
    while(it !=  characteristics.end())
    {
        set<string>::iterator it2 = it;
        while(it2 != characteristics.end())
        {
            // if(*it == *it2)
            //     it2++;
            //     continue;
            if(checkOverlap(*it, *it2, traits))
            {
                works = false;
            }
            it2++;
        }
        it++;
    }

    if(works)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    fclose(stdin);
    fclose(stdout);
}