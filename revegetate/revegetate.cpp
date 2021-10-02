#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int N, M, answer;
int L[100001];
vector<int> S_nbrs[100001], D_nbrs[100001];
bool impossible;

void visit(int x, int v)
{
    L[x] = v;
    for (auto n : S_nbrs[x])
    {
        if (L[n] == 3 - v)
            impossible = true;
        if (L[n] == 0)
            visit(n, v);
    }
    for (auto n : D_nbrs[x])
    {
        if (L[n] == v)
            impossible = true;
        if (L[n] == 0)
            visit(n, 3 - v);
    }
}

int main(void)
{
    freopen("revegetate.in", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        string s;
        cin >> s;
        cin >> a >> b;
        if (s == "S")
        {
            S_nbrs[a].push_back(b);
            S_nbrs[b].push_back(a);
        }
        if (s == "D")
        {
            D_nbrs[a].push_back(b);
            D_nbrs[b].push_back(a);
        }
    }

    for (int i = 1; i <= N; i++)
        if (!L[i])
        {
            visit(i, 1);
            answer++;
        }

    freopen("revegetate.out", "w", stdout);
    if (impossible)
        cout << "0\n";
    else
    {
        cout << "1";
        for (int i = 0; i < answer; i++)
            cout << "0";
        cout << "\n";
    }
    return 0;
}