#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;

struct Point{
    int x, y;
    Point(int x = 0, int y = 0):x(x),y(y){}
};

typedef Point Vector;
Vector operator+ (const Vector& A, const Vector& B)
{
    return Vector(A.x + B.x, A.y + B.y);
}
const int MAXC = 16;
char grid[MAXC][MAXC];
int R, C;
inline bool valid(const Point& p)
{
    return p.x >= 0 && p.x < R && p.y < C && p.y >= 0;
}

int main(int argc, char const *argv[])
{
    char buf[MAXC]; int buflen;
    const Vector dLeft(0, -1), dUp(-1, 0), dRight(0, 1), dDown(1, 0);
    for (int t = 1; scanf("%d%d", &R, &C) == 2 && R; t++)
    {
        vector<Point> eligible;
        vector<int> down, across;
        if (t > 1) puts("");
        printf("puzzle #%d:\n", t);
        _for(i, 0, R)
        {
            scanf("%s", &grid[i]);
            _for(j, 0, C)
            {
                if (grid[i][j] == '*')
                {
                    continue;
                }
                Point p(i, j), left = p + dLeft, up = p + dUp;
                bool isCross = !valid(left) || grid[left.x][left.y] == '*';
                bool isDown = !valid(up) || grid[up.x][up.y] == '*';
                if (isCross) across.push_back(eligible.size());
                if (isDown) down.push_back(eligible.size());
                if (isCross || isDown) eligible.push_back(p);
            }
        }
        puts("Across");
        for (auto n : across)
        {
            buflen = 0, memset(buf, 0, sizeof(buf));
            Point p = eligible[n];
            while (valid(p) && grid[p.x][p.y] != '*')
            {
                buf[buflen++] = grid[p.x][p.y];
                p = p + dRight;
            }
            printf("%3d.%s\n", n + 1, buf);
        }
        puts("Down");
        for (auto n : down)
        {
            buflen = 0, memset(buf, 0, sizeof(buf));
            Point p = eligible[n];
            while (valid(p) && grid[p.x][p.y] != '*')
            {
                buf[buflen++] = grid[p.x][p.y];
                p = p + dDown;
            }
            printf("%3d.%s\n", n + 1, buf);
        }
    }
    system("pause");
    return 0;
}
