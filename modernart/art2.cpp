/*
ID: jaising1
LANG: C++
TASK: art
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;


vector<int> turnIntoVector(string number)
{
    vector<char> charVec(number.begin(), number.end());
    vector<int> list;
    for(int i = 0; i < charVec.size();i++)
    {
        char a = charVec[i];
        int ia = ((int)a) -((int)'0');
        list.push_back(ia);
    }
    return list;
}
void printGrid(vector<vector<int>> colorings)
{
   int N = colorings.size();
   for(int i = 0; i < N; i++)
   {
       for(int j = 0; j < N; j++)
       {
           cout << colorings[i][j] << " ";
       }
       cout << endl;
   } 
}
vector<int> findDimensions(vector<vector<int>> colorings, int number)
{
    int N = colorings.size();
    int top, bottom, left, right;
    top = -1;
    bottom = -1;
    left = -1;
    right = -1;

    for(int i=0;i < N; i++)
    {
        for(int j=0;j < N; j++)
        {
            auto color = colorings[i][j];
            if(color == number)
            {
                if(top == -1)
                {
                    top = i;
                }

                bottom = i;
                if(left == -1)
                {
                    left = j;
                }                
                if (j<left)
                {
                    left = j;
                }
                if(j>right)
                {
                    right = j;
                }
            }
        } 
    }

    vector<int> dimensions = {number, top, bottom, left, right};
    return dimensions;
}

vector<int> allPresentColors(vector<vector<int>> colorings)
{
    set<int> colors;
    int N = colorings.size();
    for(int i=0;i < N; i++)
    {
        for(int j=0;j < N; j++)
        {
            auto color = colorings[i][j];
            if(color == 0)
                continue;
            if(colors.count(color)==1)
            {
                continue;
            }
            else
                colors.insert(color);
        }
    }
    
    return vector<int> (colors.begin(), colors.end());
}

vector<vector<int>> printRec(vector<vector<int>> original, vector<int>colorDimensions)
{
 
    int number,top,bottom,left,right,N;
    number = colorDimensions[0];
    top = colorDimensions[1];
    bottom = colorDimensions[2];
    left = colorDimensions[3];
    right = colorDimensions[4];
    N = original.size();
    vector<vector<int>> copyBoard = original;

    for(int i = top; i <= bottom;i++)
    {
        for(int j = left; j <= right;j++)
        {

            copyBoard[i][j] = number;
        }
    }

    return copyBoard;
}

int findAllBottoms(int N, vector<vector<int>> colorings, vector<vector<int>> rectangles)
{
    set<int> possibleColors;
   do
    {
    
        if(possibleColors.count(rectangles[0][0])==1)
            continue;
        vector<vector<int>> copy(N,vector<int>(N,0));
        for(int i = 0; i < rectangles.size();i++)
        {
            copy = printRec(copy, rectangles[i]);
        }

        if(copy == colorings)
        {
            possibleColors.insert(rectangles[0][0]);
        }
        if(possibleColors.size()==rectangles.size())
            break;
       
    } while(next_permutation(rectangles.begin(),rectangles.end()));
    return possibleColors.size();

}


FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"
int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int N;
    cin >> N;
    vector<vector<int>> colorings;
    for(int i = 0; i < N; i++)
    {   
        vector<int> row;
        string rowNum;
        cin >> rowNum;
        row = turnIntoVector(rowNum);
        colorings.push_back(row);
    }


    vector<int> colorsPresent = allPresentColors(colorings);

    vector<vector<int>> rectangles;
    for(int i = 0; i < colorsPresent.size();i++)
    {
        rectangles.push_back(findDimensions(colorings, colorsPresent[i]));
    }

    cout << findAllBottoms(N, colorings, rectangles) << endl;

    fclose(stdin);
    fclose(stdout);
}