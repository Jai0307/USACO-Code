/*
ID: jaising1
LANG: C++
TASK: pprime
*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <math.h> 

using namespace std;

FILE *fin;
ofstream fout;
#define infile "pprime.in"
#define outfile "pprime.out"

vector<int> sivOfE(int);
void reverseChar(char*);
int turnIntPal(int, int);
int turnIntPalBackwards(int);
bool primetest(int, vector<int>); 


bool primetest(int num,vector<int> primes) 
{
    
    for(int i =0;i< primes.size();i++)
    {
        if(primes[i]>pow(num,0.5))
        {
            break;
        }
        if(num%primes[i]==0)
        {
            return false;
        }
    }
    return true;

}

vector<int> sivOfE(int maxNum)
{
    vector<int> numbers;
    int index = 0;
    vector<int> primes;
    for(int i=2; i<=maxNum;i++)
    {
        numbers.push_back(i);
    }

    while(0<numbers.size())
    {   
        vector<int> compositeNums;
        int prime=numbers[index];
        primes.push_back(prime);
        for(int i=0;i<numbers.size();i++)
        {
            if(numbers[i]%prime==0)
            {
                compositeNums.push_back(numbers[i]);
            }
        }
        for(int i=0;i<compositeNums.size();i++)
        {
            numbers.erase(remove(numbers.begin(), numbers.end(), compositeNums[i]), numbers.end());
        }


    }
    return primes;
    
}

// void reverseChar(char* str) {
//     std::reverse(str, str + strlen(str));
// }
// bool isPalindrome(int number)
// {
//     char numStr[9];
//     itoa(number,numStr,10);
//     char revStr[9];
//     strcpy(revStr, numStr);
//     reverseChar(revStr);
//     int same = strcmp(numStr, revStr);
//     if(same==0)
//         return true;
//     return false;


// }



int turnIntPalBackwards(int number)
{
    int numdigits = int(floor(log10(number))) +1;

    int numCopy = number;
    int pal = (number)/10*pow(10,numdigits);
    int index=0;
    for(int i=0; i<numdigits; i++) 
    {
        pal += numCopy%10 *pow(10,numdigits-1-i);
        numCopy = numCopy/10;

    }
    return pal;
}


vector<int> findOddDigPal(int digits)
{
    int backHalf = digits/2+1;
    vector<int> pals;
    vector<int> xDigNums;
    for(int i=pow(10,backHalf-1);i<pow(10,backHalf);i++)
    {
        xDigNums.push_back(i);
    }
    // for(int i=0; i<xDigNums.size();i++)
    // {
    //     cout<< xDigNums[i] << endl;
    // }
    for(int i=0;  i< xDigNums.size();i++)
    {
        pals.push_back(turnIntPalBackwards(xDigNums[i]));
    }
    return pals;
}


vector<int> oddDigitPalindromes(int number,int min,vector<int> primes)
{
    int digits = int(floor(log10(number))) +1;
    int startingNums;
    vector<int> pals;
    for(int i=1;i<=digits;i++)
    {
        if(i%2 == 1)
        {
            vector<int> iPals = findOddDigPal(i);
            for(int i=0; i< iPals.size();i++)
            {
                if(iPals[i]<min || iPals[i] > number)
                {
                    continue;
                }
                if(primetest(iPals[i],primes))
                {
                    pals.push_back(iPals[i]);

                }
            }
        }
    }
    if(min<=11 && number>=11)
    {
        pals.push_back(11);
    }
    sort(pals.begin(),pals.end());
    return pals;
}



// vector<int> primesUnder10000 = sivOfE(10000);   


int main()
{
    // cout<< "hello" << endl;
    fin = fopen("pprime.in","r");
    fout.open(outfile, ios::out);

    int minNum, maxNum;
    fscanf(fin,"%d %d", &minNum, &maxNum);
    vector<int> primes = sivOfE(floor(pow(maxNum,0.5)));

    // cout<< "hello2" << endl;
    // cout << minNum << endl;
    // cout << maxNum << endl;

    vector<int> palprimes = oddDigitPalindromes(maxNum,minNum,primes);
    for(int i=0; i<palprimes.size();i++)
    {
        fout<< palprimes[i] << "\n";
    }

}