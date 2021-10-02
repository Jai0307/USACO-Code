/*
ID: jaising1
LANG: C++
TASK: blist
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int S[101], T[101], B[101];
 
int main(void) {
  ifstream fin ("blist.in");
  fin >> N;
  for (int i=1; i<=N; i++) {
    fin >> S[i] >> T[i] >> B[i];
  }

  int max_buckets = 0;
  for (int time=1; time<=1000; time++) {
    int buckets_at_this_time = 0;
    for (int i=1; i<=N; i++) {
      if (S[i] <= time && time <= T[i]) {
        buckets_at_this_time += B[i];
      }
    }
    max_buckets = max(max_buckets, buckets_at_this_time);
  }
  
  ofstream fout ("blist.out");
  fout << max_buckets << "\n";
  
  return 0;
}