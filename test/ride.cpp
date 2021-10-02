/*
ID: jaising1
LANG: C++
TASK: $1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

fstream fin;
fstream fout;
#define infile "ride.in"
#define outfile "ride.out"

int main(){
    fin.open(infile);
    fout.open(outfile, ios::out);

    vector<string> vec;

    for(int i=0; i<5; i++){
        string s = "hello";
        vec.push_back(s);
    }

    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << endl;
    }d

    if (fin.is_open()){   //checking whether the file is open
        string line;
        while(getline(fin, line)){ //read data from file object and put it into string.
            cout << line << "\n"; //print the data of the string
        }
        fin.close(); //close the file object.
    }

    if(fout.is_open()){
        fout << "Testing 1" << endl;
        fout << "Testing 2" << endl;
    }

    fout.close();
}

