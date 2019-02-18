#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;

struct Point 
{
    int x, y;
    Point(int x = 0, int y = 0):x(x), y(y){};
    bool operator < (const Point& a)const { return x < a.x || (a.x == x && y < a.y);}

};
set<Point> input;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, left = 0, right = 0;
        cin >> n;
        while (n--)
        {
            int x, y;
            cin >> x >> y;
            input.insert(Point{ x, y});
            left = min(x, left);
            right = max(x, right);
        }
        int mid = (right + left) / 2;
        int flag = 1;
        for (set<Point> :: iterator it = input.begin(); it != input.end(); it++)
        {
            if ((*it).x == mid) continue;
            int dc = abs((*it).x - mid) * 2;
            cout << it -> x << " " << it -> y << " " << it -> x + dc << endl;
            if ((*it).x < mid)
            {
                
                if (!input.count(Point{it -> x + dc, it -> y})) {flag = 0;  cout << it -> x << " " << it -> y << " " << it -> x + dc << endl; break;}
            }
            else if ((*it).x > mid)
            {
                if (!input.count(Point{it -> x - dc, it -> y})) {flag = 0; cout << it -> x << " " << it -> y << " " << it -> x + dc << endl; break;}
            }
        }
        if (flag) cout << "YES"; else cout << "NO";
    }
    system("pause");
    return 0;
}
