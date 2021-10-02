/*
ID: jaising1
LANG: C++
TASK: angry
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;


int getScore(int start, int direction, vector<int> positions) 
{
	int radius = 1;
	int prev = start;

	while(prev >= 0 && prev < positions.size()) {
		int next = prev;
		while(next + direction >= 0 && next + direction < positions.size() && abs(positions[next + direction] - positions[prev]) <= radius) 
        {
			next += direction;
		}

		if(next == prev)
        {
			break;
		}

		prev = next;
		radius++;
	}

	return abs(prev - start);
}


FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int N = 0;
    cin >> N;
    vector<int> positions;
    for(int i=0; i<N;i++)
    {
        int pos = 0;
        cin >> pos;
        positions.push_back(pos);
    }
    sort(positions.begin(),positions.end());
    int score = 0;
    for(int i = 0; i < N; i++) 
    {
		score = max(score, getScore(i, -1, positions) + getScore(i, 1, positions) + 1);
	}   
    cout << score << endl;

    fclose(stdin);
    fclose(stdout);
}