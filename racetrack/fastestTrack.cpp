#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdint>

using namespace std;

vector<int> possibleAccelerations = {-10, -8, -6, -4, -2, 0, 2, 4, 6, 8, 10};
int maxAcceleration = 10;

struct Point
{
    int x;
    int y;
    int xvel = 0;
    int yvel = 0;
};

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false; // Doesn't fall in any of the above cases
}

// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)
        return false;

    // Create a point for line segment from p to infinite
    Point extreme = {9999, p.y};

    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i + 1) % n;

        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
                return onSegment(polygon[i], p, polygon[next]);

            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count & 1; // Same as (count%2 == 1)
}

bool inTrack(Point outsidePoly[], Point insidePoly[], int nOut, int nIn, Point p)
{
    // fails if point is on edge!!!!!!
    return isInside(outsidePoly, nOut, p) && !isInside(insidePoly, nIn, p);
}

bool intersectPolygon(Point poly[], Point e1, Point e2, int n)
{
    // checks if segment with two endpoints intersects a polygon
    for (int i = 0; i < n - 1; i++)
    {
        if (doIntersect(e1, e2, poly[i], poly[i + 1]))
            return true;
    }
    return doIntersect(e1, e2, poly[n - 1], poly[0]);
}

bool intersectsTrack(Point insidePoly[], Point outsidePoly[], int n1, int n2, Point e1, Point e2)
{
    //checks if segment intersects the given track
    return intersectPolygon(outsidePoly, e1, e2, n1) || intersectPolygon(insidePoly, e1, e2, n2);
}

// Point greedyPath(Point p, vector<int> accelerations, int turns, Point e1, Point e2, Point outsidePoly[], Point insidePoly[], int nOut, int nIn)
// {
//     //given a checkpoint line and a point, possible accelerations and select turns get the best path for that checkpoint
//     //will not be best overall as this is a greedy algro
//     vector<vector<vector<int>>> allAccelerations;

//     vector<vector<int>> bestAccelerations;
//     Point originalP = p;
//     Point oldP = p;

//     vector<vector<int>> usedAccelerations;

//     bool works = true;
//     int turns = 0;
//     int minturns = 0;
//     for (int j = 0; j < allAccelerations.size(); j++)
//     {
//         works = true;
//         p = originalP;
//         for (int i = 0; i < usedAccelerations.size(); i++)
//         {
//             //checks each turn in specific set to see if it works, or is worthless
//             Point oldP = p;
//             int Ax, Ay;
//             Ax = usedAccelerations[i][0];
//             Ay = usedAccelerations[i][1];
//             p.x += p.xvel + Ax / 2;
//             p.y += p.yvel + Ay / 2;
//             p.xvel += Ax;
//             p.yvel += Ay;
//             if (!inTrack(outsidePoly, insidePoly, nOut, nIn, p))
//             {
//                 works = false;
//                 break;
//             }
//             else if (!intersectsTrack(insidePoly, outsidePoly, nIn, nOut, p, oldP))
//             {
//                 works = false;
//                 break;
//             }
//             else if (doIntersect(e1, e2, p, oldP))
//             {
//                 turns = i + 1;
//                 break;
//             }
//         }
//         if (!works)
//         {
//             continue;
//         }
//         if (turns < minturns)
//         {
//             minturns = turns;
//             bestAccelerations = usedAccelerations;
//         }
//     }

//     for (int i = 0; i < bestAccelerations.size(); i++)
//     {
//         cout << "ax: " << bestAccelerations[i][0] << " ay: " << bestAccelerations[i][1] << endl;
//     }
//     return p;
// }

vector<vector<int>> greedyPathBetter(Point p, vector<int> accelerations, int turns, Point e1, Point e2, Point outsidePoly[], Point insidePoly[], int nOut, int nIn)
{
    vector<vector<int>> futureAccelerations;
    vector<vector<int>> currbestAccelerations;
    int bestSize = 999;

    Point ogP = p;
    int xa, ya;
    for (int Ax = 0; Ax < accelerations.size(); Ax++)
    {
        for (int Ay = 0; Ay < accelerations.size(); Ay++)
        {
            p = ogP;
            if (Ax ^ 2 + Ay ^ 2 > maxAcceleration ^ 2)
                continue;
            p.x += p.xvel + Ax / 2;
            p.y += p.yvel + Ay / 2;
            p.xvel += Ax;
            p.yvel += Ay;
            if (!inTrack(outsidePoly, insidePoly, nOut, nIn, p))
            {
                continue;
            }
            else if (!intersectsTrack(insidePoly, outsidePoly, nIn, nOut, p, ogP))
            {
                continue;
            }
            else if (doIntersect(e1, e2, p, ogP) && turns != 6)
            {
                xa = Ax;
                ya = Ay;
                goto exit;
            }
            else if (turns == 6)
            {
                vector<vector<int>> noAccelerationsList;
                vector<int> noAccelerations;
                noAccelerationsList.push_back(noAccelerations);
                return noAccelerationsList;
            }
            vector<vector<int>> newAccelerations = greedyPathBetter(p, accelerations, turns + 1, e1, e2, outsidePoly, insidePoly, nOut, nIn);
            if (newAccelerations[0].size() == 0)
            {
                vector<vector<int>> noAccelerationsList;
                vector<int> noAccelerations;
                noAccelerationsList.push_back(noAccelerations);
                return noAccelerationsList;
            }
            if (newAccelerations.size() < bestSize)
            {
                currbestAccelerations = {};
                bestSize = newAccelerations.size() + 1;
                vector<int> currAccelerations{Ax, Ay};
                currbestAccelerations.push_back(currAccelerations);
                currbestAccelerations.insert(futureAccelerations.end(), newAccelerations.begin(), newAccelerations.end());
            }
        }
    }
    return currbestAccelerations;

exit:
    vector<int> bestAccelerations;
    vector<vector<int>> bestAccelerationsList;

    bestAccelerations.push_back(xa);
    bestAccelerations.push_back(ya);
    bestAccelerationsList.push_back(bestAccelerations);
    return bestAccelerationsList;
}

int main()
{
    freopen("track.txt", "r", stdin);
    freopen("track.out", "w", stdout);
    int n1, n2, c;
    cin >> n1 >> n2 >> c;
    Point p;
    Point insidePoly[1000];
    Point outsidePoly[1000];
    vector<vector<Point>> checkpoints;
    for (int i = 0; i < n1; i++)
    {
        Point p;
        int x, y;
        cin >> x >> y;
        p.x = x;
        p.y = y;
        insidePoly[i] = p;
    }
    for (int i = 0; i < n2; i++)
    {
        Point p;
        int x, y;
        cin >> x >> y;
        p.x = x;
        p.y = y;
        outsidePoly[i] = p;
    }

    for (int i = 0; i < c; i++)
    {
        Point e1, e2;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        e1.x = x1;
        e2.x = x2;
        e1.y = y1;
        e2.y = y2;
        vector<Point> checkpoint;
        checkpoint.push_back(e1);
        checkpoint.push_back(e2);
    }

    for (int i = 0; i < c; i++)
    {
        vector<vector<int>> accelerationsInCheckpoint = greedyPathBetter(p, possibleAccelerations, 0, checkpoints[i][0], checkpoints[i][1], outsidePoly, insidePoly, n2, n1);
        for (int i = 0; i < accelerationsInCheckpoint.size(); i++)
        {
            int Ax = accelerationsInCheckpoint[i][0];
            int Ay = accelerationsInCheckpoint[i][1];

            cout << "Ax = " << Ax << "Ay = " << Ay << endl;
            p.x += p.xvel + Ax / 2;
            p.y += p.yvel + Ay / 2;
            p.xvel += Ax;
            p.yvel += Ay;
        }
    }
}