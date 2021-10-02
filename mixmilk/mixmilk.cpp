/*
ID: jaising1
LANG: C++
TASK: mixmilk
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void pour(int& c1, int& m1, int& c2, int& m2) {
  int amt = min(m1, c2 - m2);
  m1 -= amt;
  m2 += amt;
}
 

FILE* fin;
fstream fout;
int main(){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int c1, c2, c3;
    int m1, m2, m3;
    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
    for (int i = 0; i < 33; i++)
    {
        pour(c1, m1, c2, m2);
        pour(c2, m2, c3, m3);
        pour(c3, m3, c1, m1);
    }
    pour(c1, m1, c2, m2);
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;

    fclose(stdin);
    fclose(stdout);
}

