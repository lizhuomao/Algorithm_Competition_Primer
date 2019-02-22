#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

struct Point
{
    int x, y;
    Point(int x, int y) : x(x), y(y){}
};
typedef Point Vector;
const int N = 8;
const Vector dir[N] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

Vector operator+ (const Vector &a, const Vector &b) { return Vector(a.x + b.x, a.y + b.y);}
bool operator== (const Vector &a, const Vector &b) { return a.x == b.x && a.y == b.y;}
bool isRange(int x, int left, int right)
{
    if (left > right) return isRange(x, right, left);
    return x >= left && x <= right;
}
Point toPoint(const char *s)
{
    return Point(s[0] - 'a', s[1] - '1');
}
bool isValid(const Point &p)
{
    return isRange(p.x, 0, N - 1) && isRange(p.y, 0, N - 1);
}
int solve(const Point &from, const Point &to)
{
    int visit[N][N];
    memset(visit, -1, sizeof(visit));
    queue<Point> q;
    q.push(from);
    visit[from.x][from.y] = 0;
    while (!q.empty())
    {
        const Point &f = q.front();
        q.pop();
        int d = visit[f.x][f.y];
        if (f == to) return d;
        for (int i = 0; i < N; i++)
        {
            Point np = f + dir[i];
            if (isValid(np) && visit[np.x][np.y] == -1)
            {
                visit[np.x][np.y] = d + 1;
                q.push(np);
            }
        }
    }
}

int main(void)
{
    char a[3], b[3];
    while (cin >> a >> b)
    {
        int ans = solve(toPoint(a), toPoint(b));
        cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves." << endl;
    }
    system("pause");
    return 0;
}