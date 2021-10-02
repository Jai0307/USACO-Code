/*
ID: jaising1
LANG: C++
TASK: citystate
*/

#include <iostream>
#include <cstdio>
#include <map>
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
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int N;
    cin >> N;
    int total = 0;
    map<string, int> city_state;
    for (int i = 0; i < N; i++) 
    {
		string city;
		string state;
        cin >> city >> state;
        city = city.substr(0, 2);
		if (city != state) {
			total += city_state[state + city];
		}
		city_state[city + state]++;
    }
    cout << total << endl;
    fclose(stdin);
    fclose(stdout);
}