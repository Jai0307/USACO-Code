/*
ID: jaising1
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int stringToInt(string);
FILE* fin;
fstream fout;
#define infile "ride.in"
#define outfile "ride.out"

int main(){
    // char c('\n');
    // cout << "ASCII Value of " << c << " is " << int(c) << endl;
    // char c1('\0');
    // cout << "ASCII Value of " << c1 << " is " << int(c1)<< endl;
    // return 0;

    fin = fopen(infile, "r");
    fout.open(outfile, ios::out);
    char comet[50];
    char group [50];
    // string comet;
    // string group;

    fscanf(fin, "%s %s", comet, group);

    int cometNum = 0;
    int groupNum = 0;
    cometNum = (stringToInt(comet)/1)%47;
    groupNum = stringToInt(group)%47;
    // cout<<comet.size()<<endl;
    // cout<<group.size()<<endl;

    if (cometNum == groupNum)
    { 
        fout << "GO\n";
    }
    else
    {
        fout << "STAY\n";
    }

    fclose(fin);
    fout.close();
}

int stringToInt(string name)
{
    int value = 1;
    int character = 0;
    for(int i = 0; i< name.length();i++)
    {
        character = name[i];
        if(character == 10 || character == 0 || character == 32)
        {
            // cout << "Found new line" << endl;
            continue;
        }
        character = name[i]-64;
        if(character<=0){
            // cout << "character error: " << character << endl;
        }
        // cout<<name[i]<< ": " <<character<<endl;
        value *= character;
    }  
    return value;

}

