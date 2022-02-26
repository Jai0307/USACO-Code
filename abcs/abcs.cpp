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
const int MX = 10e6;

int N;
vector<int> vals;
set<multiset<int>> sols;

void check_sol(int sum, int b, int c) {
	int a = sum-b-c;
	set<int> s{0,a,b,c,a+b,b+c,c+a,a+b+c};
	for (int t: vals) 
		if (!s.count(t))
			return;
	sols.insert({a,b,c});
}
 
void test(int sum) {
	set<int> candidates;
	for (int t: vals) {
		if (t > sum) 
			return;
		if (t == 0 || t == sum)
			continue;
		candidates.insert(min(t,sum-t));
	}
	int a = *candidates.begin();
	int b = *++candidates.begin();
	check_sol(sum,a,b);
	check_sol(sum,a,sum-b);
}

int solve() 
{
	cin >> N; 
	vals.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> vals[i];
	}
	
	vals.push_back(0);
	sols.clear();
	for (int i = 0; i < vals.size(); i++)
		for (int j = i+1; j < vals.size(); j++)
			test(vals[i]+vals[j]);
	return sols.size();
}

int main()
{
    // freopen("abcs.in", "r", stdin);
    // freopen("abcs.out", "w", stdout);
    int T;
    cin >> T;
    while(T-->0)
    {
        cout << solve() << endl;
    }
}