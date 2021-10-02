/*
ID: jaising1
LANG: C++
TASK: paint
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

FILE* fin;
fstream fout;
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> c1, c2;
    c1.push_back(a);
    c1.push_back(b);
    c2.push_back(c);
    c2.push_back(d);
    int min = 9999;
    int max =  0;
    int painted = 0;
    for(int i = 0; i <= 100;i++)
    {
        if((a<= i && b>= i+1) || (c<= i && d>= i+1))
        {
            // cout << i << endl;
            painted++;
        }
    }
    cout << painted;


    fclose(stdin);
    fclose(stdout);
}