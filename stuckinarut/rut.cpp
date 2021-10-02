/*
ID: jaising1
LANG: C++
TASK: rut
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

FILE* fin;
fstream fout;
#define infile "censor.in"
#define outfile "censor.out"


struct Cow
{
    int startX;
    int startY;
    bool stopped = false;;
    int dist;
    string dir;
    int stopDistance;
    bool infinite = false;
    
};

void printCow(Cow c){
    cout << "cow" << ": " << "x: " << c.x << " y: " << c.y << " stopped? " << c.stopped <<" infinite: " << c.infinite << endl;
}

void moveCow(Cow& c)
{
    // cout << "im here! moveCow" << endl;
    if (c.stopped || c.infinite)
    {
        return;
    }
    if (c.dir == "E")
    {
        c.x = c.x + 1;
    }
    else
    {
        c.y = c.y + 1;
    }
}

bool checkDone(vector<Cow>& cows)
{
    for (int i = 0; i < cows.size(); i++)
    {
        if(!cows[i].stopped && !cows[i].infinite)
        {
            return false;
        }
    }
    return true;
}

// void checkAhead(vector<Cow>& cvec)
// {
//     for(int i = 0; i < cvec.size(); i++)
//     {
//         if(cvec[i].stopped || cvec[i].infinite)
//             continue;
//         bool ahead = true;
//         for(int j = 0; j < cvec.size(); j++)
//         {
//             if(i==j)
//                 continue;

//             if(cvec[i].dir == "E")
//             {
//                 if(cvec[j].dir == "N" && cvec[j].x>cvec[i].x)
//                 {
//                     ahead = false;
//                     break;
//                 }
//                 else if(cvec[j].dir == "E" && cvec[j].x>cvec[i].x && cvec[j].y==cvec[i].y)
//                 {
//                     ahead = false;
//                     break;
//                 }
//             }
//             else
//             {
//                 if(cvec[j].dir == "E" && cvec[j].y>cvec[i].y)
//                 {
//                     ahead = false;
//                     break;
//                 }
//                 else if(cvec[j].dir == "N" && cvec[j].y>cvec[i].y && cvec[j].x==cvec[i].x)
//                 {
//                     ahead = false;
//                     break;
//                 }
//             }
//         }
//         if(ahead)
//         {
//             cvec[i].infinite = true;
//         }
//     }

// }

void checkCowPos(vector<Cow>& cvec){
    for(int i = 0; i < cvec.size(); i++)
    {
        if(cvec[i].stopped || cvec[i].infinite)
            continue;
        bool ahead = true;
        for(int j = 0; j < cvec.size(); j++)
        {
            if(i==j)
                continue;

            if(cvec[i].dir==cvec[j].dir){
                if((cvec[i].x==cvec[j].startX) && (cvec[i].y==cvec[j].startY)){
                    cvec[i].stopped=true;
                }
                else if(cvec[i].dir == "E" && cvec[j].x > cvec[i].x && cvec[i].y == cvec[j].y)
                {
                    ahead = false;
                }
                else if(cvec[i].dir == "N" && cvec[j].y > cvec[i].y && cvec[i].x == cvec[j].x)
                {
                    ahead = false;
                }
            }else
            {
                if(cvec[j].dir=="N")
                {
                    if(cvec[i].x == cvec[j].x){
                        if(cvec[j].startY <= cvec[i].y && cvec[j].y > cvec[i].y)
                        {
                            cvec[i].stopped = true;
                        }
                        else
                            ahead = false;
                    }
                    else if(cvec[j].x > cvec[i].x)
                    {
                        ahead = false;
                    }
                }
                else if(cvec[j].dir=="E")
                {
                    if(cvec[i].y == cvec[j].y){
                        if(cvec[j].startX <= cvec[i].x && cvec[j].x > cvec[i].x)
                        {
                            cvec[i].stopped = true;
                        }
                        else
                            ahead = false;
                    }
                    else if(cvec[j].y > cvec[i].y)
                    {
                        ahead = false;
                    }

                }
            }
        }
        if(cvec[i].stopped)
            cvec[i].stopDistance = cvec[i].x + cvec[i].y - cvec[i].startX - cvec[i].startY;
        else if(ahead)
            cvec[i].infinite = true;
    }
}



int main()
{

    Cow c;
    for (int i=0; i<1000000000; i++){
        moveCow(c);
    }
    cout <<"done"<< endl;
    return 0;
    // freopen("rut.in", "r", stdin);
    // freopen("rut.out", "w", stdout);
    int N;
    cin >> N;

 

    vector<Cow> cows;
    for (int i = 0; i < N; i++)
    {
        Cow cow1;
        int x, y;
        string dir;

        cin >> cow1.dir >> cow1.startX >> cow1.startY;
        cow1.x = cow1.startX;
        cow1.y = cow1.startY;
        cows.push_back(cow1);

    }
    // int run =0;
    checkCowPos(cows);
    while(!checkDone(cows))
    {
        bool done = checkDone(cows);
        for(int i = 0; i < cows.size(); i++)
        {
            moveCow(cows[i]);
        } 
        checkCowPos(cows);
        
    }
    for(int i = 0; i < cows.size();i++)
    {
        if(cows[i].stopped == false)
        {
            cout << "Infinity" << endl;
        }
        else
        
        {
            cout << cows[i].stopDistance << endl;
        }
    }
    // fclose(stdin);
    // fclose(stdout);

}