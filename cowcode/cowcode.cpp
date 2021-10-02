/*
ID: jaising1
LANG: C++
TASK: cowcode
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

string rotateRight(string s)
{
    long long len = s.length();
    string a = s.substr(len - 1);
    string b = s.substr(0, len - 1);

    return a + b;
}
void functionVec(vector<char> &cvec)
{
    int len = cvec.size();
    cvec.push_back(cvec[len - 1]);
    for (int i = 0; i < len - 1; i++)
    {
        cvec.push_back(cvec[i]);
    }
}
string functionString(string s)
{
    return s + rotateRight(s);
}

bool reduceIndex(long long &N, long long len)
{
    if (N < len)
    {
        return false;
    }
    else
    {
        while (len * 2 < N + 1)
        {
            len = len * 2;
        }

        if (N == len)
        {
            N -= 1;
            // cout << "N is the last term" << endl;
        }
        else
        {
            N -= len + 1;
        }
        return true;
    }
}

FILE *fin;
fstream fout;
int main()
{
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);
    string s;
    long long N;
    cin >> s >> N;
    N--;
    // cout << N << endl;
    long long len = s.length();
    vector<char> sVec(s.begin(), s.end());

    // while(sVec.size() <= N)
    // {
    //     functionVec(sVec);
    //     // for(int i = 0; i < sVec.size();i++)
    //     // {
    //     //     cout << sVec[i];
    //     // }
    //     // cout<<endl;
    // }
    // cout << sVec[N-1] << endl;

    while (reduceIndex(N, len))
    {
    }
    // cout << N << endl;

    cout << s.substr(N, 1) << endl;
    fclose(stdin);
    fclose(stdout);
}