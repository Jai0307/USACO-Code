/*
ID: jaising1
LANG: C++
TASK: madeup
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> alist, blist, clist;


bool works(int i, int j)
{
    int a = alist[i];
    cout << "a: " << a << endl;
    int c = clist[j];
    cout << "c: " << c << endl;

    if(c > 0 && c <= clist.size())
    {
        int b = blist[c-1];
        cout << "b: " << b << endl;

        return a == b;
        
    }
    return false;
}


int main(){
    freopen("madeup.in", "r", stdin);
    freopen("madeup.out", "w", stdout);
    int N;
    cin >> N;
    for(int i=0; i < N; i++)
    {
        int a = 0;
        cin >> a;
        alist.push_back(a);
    }
    for(int i=0; i < N; i++)
    {
        int a = 0;
        cin >> a;
        blist.push_back(a);
    }
    for(int i=0; i < N; i++)
    {
        int a = 0;
        cin >> a;
        clist.push_back(a);
    }
    int number = 0;
    for(int i = 0; i < alist.size();i++)
    {
        for(int j = 0; j < alist.size();j++)
        {
            cout << "i: " << i << " j: " << j << endl;
            cout << works(i,j) << endl;
            if(works(i,j))
                number++;
        }
    }
    cout << number;


    fclose(stdin);
    fclose(stdout);
}