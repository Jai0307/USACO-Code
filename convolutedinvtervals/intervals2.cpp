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



int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> ivals(N);
	for (auto &ival : ivals)
		cin >> ival.first >> ival.second;
	vector<int64_t> win_start(2 * M + 1), win_end(2 * M + 1);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			++win_start.at(ivals.at(i).first+ivals.at(j).first);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			++win_end.at(ivals.at(i).second+ivals.at(j).second);
	int64_t win_count = 0;
	for (int i = 0; i <= 2 * M; ++i) {
		win_count += win_start.at(i);
		cout << win_count << "\n";
		win_count -= win_end.at(i);
	}
}