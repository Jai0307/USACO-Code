/*
ID: jaising1
LANG: C++
TASK: hps
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
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
int n;
	cin >> n;
	vector<int> h(n + 1), p(n + 1), s(n + 1);

	for (int i = 0; i < n; i++) {
		h[i + 1] = h[i];
		p[i + 1] = p[i];
		s[i + 1] = s[i];

		char cur;
		cin >> cur;
		if (cur == 'P') p[i + 1]++;
		else if (cur == 'H') h[i + 1]++;
		else s[i + 1]++;
	}

	int sol = 0;

	for (int i = 1; i <= n; i++) {
		auto update = [&] (vector<int>& a, vector<int>& b) {
				sol = max(sol, a[i] + b[n] - b[i]);
		};
		update(h, p);
		update(h, s);
		update(p, s);
		update(p, h);
		update(s, h);
		update(s, p);
	}
    cout << sol << endl;
    fclose(stdin);
    fclose(stdout);
}