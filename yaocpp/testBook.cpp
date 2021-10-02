#include <cstdio>


using namespace std;


int main() {
    freopen("template.in", "r", stdin);
    freopen("template.out", "w", stdout);
}


// or 


#include <fstream>
using namespace std;
int main() 
{
    ifstream fin("template.in");
    ofstream fout("template.out");
}


for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
{
    cout << *it; //prints the values in the vector using the pointer
}


for(auto element : v) 
{
    cout << element; //prints the values in the vector
}


for(int element : set)
{
    cout << element << " ";
}
cout << endl;

// A note on unordered sets and maps: In USACO contests, they’re generally fine, but in
// CodeForces contests, you should always use sorted sets and maps. This is because the built-in
// hashing algorithm is vulnerable to pathological data sets causing abnormally slow runtimes,
// in turn causing failures on some test cases.
