/*
ID: jaising1
LANG: C++
TASK: rut2
*/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

class Cow
{
    public:
        int startX;
        int startY;
        int x;
        int y;
        bool stopped = false;;
        int dist;
        string dir;
        int stopDistance;
        bool infinite = false;
        int index;
        bool operator < (const Cow &c) const {
            if(dir == "E")
                return startY < c.startY;
            else
                return startX < c.startX;
        }
    public: vector<Cow> sortCows(vector<Cow> cows);
};

vector<Cow> Cow::sortCows(vector<Cow> cows)
{
    vector<Cow> copy = cows;
    std::sort(copy.begin(), copy.end());
    return copy;
}

void printCow(Cow c){
    cout << "cow" << ": " << "startx: " << c.startX << " starty: " << c.startY << ": " << "x: " << c.x << " y: " << c.y << " stopped? " << c.stopped <<" infinite: " << c.infinite << endl;
}

Cow findCow(vector<Cow> ce, vector<Cow>cn, int indx)
{
    for(auto it = ce.begin(); it != ce.end(); ++it)
    {
        if(( *it).index== indx)
        {
            return *it;
        }
    }
    for(auto it = cn.begin(); it != cn.end(); ++it)
    {
        if(( *it).index== indx)
        {
            return *it;
        }
    }
    Cow c;
    return c;
}


int firstOrStop(Cow c1, Cow c2)
{
    //c1 will be East always
    //c2 will be North always
    //0 means East is sooner
    //1 means North is sooner
    //2 means same time
    int x = abs(c1.startX-c2.startX);
    int y = abs(c1.startY-c2.startY);

    if (x == y){
        cout << "x = y " << endl;
        return 2;
    }
    else if(x<y){
        cout << "x < y " << endl;
        return 0;
    }
    cout << "x > y " << endl;

    return 1;


}

bool c1Sooner(Cow c1, Cow c2)
{
    
    int x1 = c1.startX;
    int y1 = c1.startY;
    int x2 = c2.startX;
    int y2 = c2.startY;
    if(c1.dir == "E")
    {
        if(c2.stopped && y1-y2>c2.y-c2.startY)
        {
            return true;
        }
        return x2-x1<=y1-y2;
    }
    else
    {
        if(c2.stopped && x1-x2>c2.x-c2.startX)
        {
            return true;
        }
        return y2-y1<=x1-x2;
    }



}


void updateCows(Cow& c1, vector<Cow>& cset)
{
    vector<Cow>::iterator it;
    // cout << "/////////////////////" << endl;
    // printCow(c1);
    if(c1.dir == "E"){
        
        cout << "c1 dir = E" << endl;
        for(it = cset.begin(); it != cset.end(); ++it)
        {
            Cow ncow = *it;
            cout << "ncow:" << endl;
            // printCow(ncow);
            bool result = c1Sooner(c1, ncow);
            if(ncow.startX<c1.startX || ncow.startY > c1.startY)
                continue;
            if(!result)
            {
                cout << "cur pos X: " << ncow.startX << " original X: " << c1.startX << endl;
                
                c1.stopDistance = ncow.startX-c1.startX;
                cout << "stopDistance = " << c1.stopDistance << endl;
                 cout << "stopped!" << endl;

                c1.stopped = true;
                return;
            }
        }
    }
    else{
        cout << "c1 dir = N" << endl;

        for(it = cset.begin(); it != cset.end(); ++it)
        {
            Cow ncow = *it;
            bool result = c1Sooner(c1, ncow);
            if(ncow.startX>c1.startX||ncow.startY < c1.startY)
                continue;
            if(!result)
            {
                cout << "im here!" << endl;
                cout << "cur pos Y: " << ncow.startY << " original Y: " << c1.startY << endl;
                c1.stopDistance = ncow.startY-c1.startY;
                cout << "stopped!" << endl;

                c1.stopped = true;
                return;
            }
        }
    }

    c1.infinite = true;
}

void updateCows2(Cow& c1, vector<Cow>& cset)
{
    // vector<Cow>::iterator it;
    // cout << "//////////////////////////////////" << endl;
    // printCow(c1);
    if(c1.dir == "E"){
        
        // cout << "c1 dir = E" << endl;
        for(int i = 0; i < cset.size();i++)
        {
            Cow &ncow = cset[i];
            // cout << "ncow: ";
            // printCow(ncow);
            bool result = c1Sooner(c1, ncow);
            // cout << "found result: " << result << endl;
            if(ncow.startX<c1.startX || ncow.startY > c1.startY){
                // cout << "continued" << endl;
                continue;
            }
            if(!result)
            {
                // cout << "cur pos X: " << ncow.startX << " original X: " << c1.startX << endl;
                
                c1.stopDistance = ncow.startX-c1.startX;
                // cout << "stopDistance = " << c1.stopDistance << endl;
                // cout << "stopped!" << endl;

                c1.stopped = true;
                return;
            }
            else if(ncow.startX-c1.startX==c1.startY-ncow.startY)
            {
                // cout << "continued because same intersection" << endl;
                continue;
            }
            else if (!ncow.stopped)
            {
                // cout << "ncow is stopped" << endl;
                ncow.stopped = true;
                ncow.stopDistance = c1.y-ncow.startY;
                ncow.y = c1.y;
            }
            else
            {
                // cout << "ncow was already stopped" << endl;
                
                continue;
            }
        }
    }
    // cout << "infinite!!" << endl;
    c1.infinite = true;
}

// void northInfinite(Cow& c1, vector<Cow>& cset)
// {
//     for
// }

#define infile "censor.in"
#define outfile "censor.out"
int main(){
    // freopen("rut1.in", "r", stdin);
    // freopen("rut2.out", "w", stdout);
    
    vector<Cow> NCows;
    vector<Cow> ECows;

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
        cow1.y =  cow1.startY;
        cow1.index = i;
        if (cow1.dir == "N")
            NCows.push_back(cow1);
        else   
            ECows.push_back(cow1);
    }
    

    sort(NCows.begin(), NCows.end());
    sort(ECows.begin(), ECows.end());
  
  
    
  
    // for(int i = 0; i < ECows.size();i++)
    // {
    //     // printCow(ECows[i]);
    // }

    // cout << "//////////////////" << endl;
  
    // for(int i = 0; i < NCows.size();i++)
    // {
    //     // printCow(NCows[i]);
    // }
  
    
    
    
    // vector<Cow>::iterator it;
    // for(it = ECows.begin(); it != ECows.end(); ++it)
    
    
    for(int i=0; i<ECows.size(); i++)    
    {
        // Cow cow = *it;
        updateCows2(ECows[i], NCows);
    }

    // for(it = NCows.begin(); it != NCows.end(); ++it)
    // for(int i=0; i<NCows.size(); i++)
    // {
    //     // Cow cow = *it;
    //     updateCows2(NCows[i], ECows);
    // }
    // cout << "///////////////////////////////" << endl;
    for(int i = 0; i < N; i++)
    {
        Cow c = findCow(NCows, ECows, i);
        
        if(!c.stopped)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            // printCow(c);
            cout << c.stopDistance << endl;
        }

    }
    // for(int i = 0; i < allCows.size();i++)
    // {
    //     if(allCows[i].stopped == false)
    //     {
    //         cout << "Infinity" << endl;
    //     }
    //     else
        
    //     {
    //         cout << allCows[i].stopDistance << endl;
    //     }
    // }

    // fclose(stdin);
    // fclose(stdout);
}