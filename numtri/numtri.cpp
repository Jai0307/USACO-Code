/*
ID: jaising1
LANG: C++
TASK: numtri
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>


using namespace std;

// FILE* fin;
ifstream fin;
ofstream fout;
#define infile "numtri.in"
#define outfile "numtri.out"

vector<int> split(string str, const string& delim)
{
    // cout << str << endl;
    vector<int> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()){
            stringstream ss(token);
            int x = 0;
            ss >> x;
            tokens.push_back(x);
        }
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());

    return tokens;
}

char* removeFirst(char* s);
char* removeLast(char* s);

int tree(vector<string>);
// int max(int, int);


main(){
    fin.open(infile);
    fout.open(outfile, ios::out);
    vector<string> vec;

    char line[2000];
    int N = 0;
    string linestr;
    getline(fin, linestr);
    // fgets(line, 1000, fin);

    int indx = 0;

    while(getline(fin, linestr)){
        vec.push_back(linestr);
    }
    
    int answer = tree(vec);
    fout << answer << "\n";
    // cout << answer << "\n";

    // fclose(fin);
    fin.close();
    fout.close();
}


int max(int a, int b)
{
    return a > b ? a : b;
}

int tree(vector<string> numbers)
{
    int newVal = 0;
    if (numbers.size()==1)
    {
        string line = numbers[0];
        vector<int> rowvec= split(line, " ");
        return rowvec[0];
    }
    string line = numbers[numbers.size()-2];
    vector<int> rowvec= split(line, " ");
    string line_plusone = numbers[numbers.size()-1];
    vector<int> rowvec_plusone = split(line_plusone, " ");
   
    for(int col = 0; col < numbers.size()-1; col++)
    {
        rowvec[col] += max(rowvec_plusone[col], rowvec_plusone[col+1]);
    }
    rowvec_plusone = rowvec;
    for(int row = numbers.size()-3; row>=0; row--)
    {
        string line_plusone = numbers[row+1];
        
        line = numbers[row];
        rowvec = split(line, " ");
        
        for(int col = 0; col < row+1; col++)
        {
            rowvec[col] += max(rowvec_plusone[col], rowvec_plusone[col+1]);
        }
        rowvec_plusone = rowvec;
    }
    return rowvec[0];
}

// int findNextNumber(char* c, int termindx) 
// {
//     int indx = 0;
//     int spacecount=0;
//     int numindx = 0;
//     char number[3];
//     while(spacecount<termindx)
//     {
//         if(c[indx]==' ')
//         {
//             spacecount++;
//         }
//         indx++;
//     }
//     while(c[indx]!=' ')
//     {
//         number[numindx] = c[indx];
//         indx++;
//     }
    
// }

char* removeLast(char* s){
    int len = sizeof(s);
    char *buff = new char[4000];
    strncpy(buff, s, len-2);
    return buff;
}

char* removeFirst(char* s){
    int len = sizeof(s);
    char *buff = new char[4000];
    strncpy(buff, s+2, len-2);
    return buff;
}



// string removeLast(char* s){
//     int pos_start = 0;
//     int pos_end = s.size()-2;
//     string temp = s.substr (pos_start, pos_end - pos_start);
//     return temp;
// }

// string removeFirst(char* s){
//     int pos_start = 2;
//     int pos_end = s.size();
//     string temp = s.substr (pos_start, pos_end - pos_start);
//     return temp;
// }

