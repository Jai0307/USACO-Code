/*
ID: jaising1
LANG: C++
TASK: badmilk
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Drinks 
{
	int t, p, m;
};

struct Sick 
{
	int p, t;
};


FILE* fin;
fstream fout;
int main(){
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int n, m, d, s;
    cin >> n >> m >> d >> s;
    const int N = n;
    vector<Drinks> drinks(d);
    vector<Sick> sick(s);
    vector<int> drank(N);

    for(int i=0; i<d; i++)
    {
		cin >> drinks[i].p >> drinks[i].m >> drinks[i].t;
		drinks[i].p--; 
        drinks[i].m--;
        drinks[i].t--;
	}
    
    for(int i=0; i<s; i++)
    {
		cin >> sick[i].p >> sick[i].t;
		sick[i].p--;
        sick[i].t--;
	}

    for(int i=0; i<d; i++)
    {
		for(int j=0; j<s; j++)
        {
			if(drinks[i].p == sick[j].p && drinks[i].t < sick[j].t)
            {
				drank[drinks[i].p].push_back(drinks[i].m);
			}
		}
	}
    fclose(stdin);
    fclose(stdout);
}