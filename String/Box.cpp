#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _ref(i, a, b) for (int i = (a); i <= (b); ++i)

using namespace std;

struct Rect
{
    int x, y;
    Rect(int x = 0, int y = 0):x(x), y(y){}
};

bool operator < (const Rect& a, const Rect& b) { return a.x < b.x || (a.x == b.x && a.y < b.y);}
bool operator == (const Rect& a, const Rect& b) { return a.x == b.x && a.y == b.y;}
bool operator != (const Rect& a, const Rect& b) { return !(a == b);}
istream& operator >> (istream& is, Rect& p) { return is >> p.x >> p.y;}
ostream& operator << (ostream& os, const Rect& p) { return os << "[" << p.x << "," << p.y << "]";}
template<typename T>
ostream& operator << (ostream& os, const vector<T>& v)
{ 
    _for (i, 0, v.size())
    {
        os << v[i] << " ";
    }
    return os;
}

vector<Rect> rects;

bool solve()
{
    sort(rects.begin(), rects.end());
    _for (i, 0, 3)
    {
        if (rects[2 * i] != rects[2 * i + 1])
            return false;
    }
    const Rect &r1 = rects[1], &r2 = rects[3], &r3 = rects[5];
    return r1.x == r2.x && r1.y == r3.x && r2.y == r3.y;
}

int main(int argc, char const *argv[])
{
    Rect r;
    while(true)
    {
        rects.clear();
        _for(i, 0, 6)
        {
            if (!(cin >> r)) return 0;
            if (r.x > r.y) swap(r.x, r.y);
            rects.push_back(r);
        }
        if (solve()) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    system("pause");
    return 0;
}

