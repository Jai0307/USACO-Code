/*
ID: jaising1
LANG: C++
TASK: censoring
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
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string text, phrase;
    cin >> text >> phrase;

    string censored;
    for(int i=0; i<text.size();i++)
    {
        censored += text[i];
        if(censored.size()>=phrase.size() && censored.substr(censored.size()-phrase.size())==phrase)
        {
            censored.resize(censored.size() - phrase.size());
        }
    }
    cout << censored << "\n";

    fclose(stdin);
    fclose(stdout);
}