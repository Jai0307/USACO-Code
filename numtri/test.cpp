#include<iostream>
#include<string>
#include<sstream>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// vector<int> split(const string& str, const string& delim)
// {
//     cout << str << endl;
//     vector<int> tokens;
//     size_t prev = 0, pos = 0;
//     do
//     {
//         pos = str.find(delim, prev);
//         if (pos == string::npos) pos = str.length();
//         string token = str.substr(prev, pos-prev);
//         if (!token.empty()){
//             stringstream ss(token);
//             int x = 0;
//             ss >> x;
//             tokens.push_back(x);
//         }
//         prev = pos + delim.length();
//     } while (pos < str.length() && prev < str.length());

//     return tokens;
// }


// char* removeLast(char* s){
//     int len = sizeof(s);
//     char *buff = new char[4000];
//     strncpy(buff, s, len-2);
//     return buff;
// }

// char* removeFirst(char* s){
//     int len = sizeof(s);
//     char *buff = new char[4000];
//     strncpy(buff, s+2, len-2);
//     return buff;
// }

int addone1(int x){
    return ++x;
}

int addone2(int& x){
    return ++x;
}


main() {
    int x = 10;
    int y = addone1(x);
    cout << "x " << x << endl;
    cout << "y " << y << endl;
    // int *x;
    // int y = 20;
    // *x = y;
    // cout<< "hello" << endl;
    // cout << "x " << x << endl;
    // // cout << "&y " << &y << endl;
    // cout << "*x " << *x << endl;
    // cout << "y " << y << endl;
    // // string s = "125 2 3 4 ";
    // // vector<int> x = split(s, " ");
    // // for(int i =0; i<x.size();i++)
    // // {
    // //     cout << x[i] << endl;
    // // }
    
}

