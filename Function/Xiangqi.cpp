#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <assert.h>
#include <algorithm>
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

struct Point 
{
    int x, y;
    Point(int x = 0, int y = 0) {}
};

Point operator + (const Point& A, const Point& B) {return Point(A.x + B.x, A.y + B.y);}
Point operator / (const Point& A, int p) {return Point(A.x / p, A.y / p);}
bool operator == (const Point& A, const Point& B) {return A.x == B.x && A.y == B.y;}
bool operator < (const Point& p1, const Point& p2) {return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);}

Point blackG, redG;
char board[16][16];
vector<Point> DIRS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}},
              HDIRS = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}},
              redPieces;
bool canFly(const Point& p1, const Point& p2, int sz = 0)
{
    bool v = (p1.x == p2.x), h = (p1.y == p2.y);
    assert(v || h);
    assert(!(v && h));
    int lx = min(p1.x, p2.x), ux = max(p1.x, p2.x);
    int ly = min(p1.y, p2.y), uy = max(p1.y, p2.y);
    int cnt = 0;
    if (v)
    {
        _for (y, ly + 1, uy)
        {
            if (board[p1.x][y] && ++cnt > sz) return false;
        }
        return cnt == sz;
    }
    _for (x, lx + 1, ux)
    {
        if (board[x][p1.y] && ++cnt > sz) return false;
    }
    return cnt == sz;
}

bool inRange(int x, int left, int right)
{
    if (left > right) return inRange(x, right, left);
    return left <= x && x <= right;
}

bool inBPalace(const Point& bPos) {return inRange(bPos.x, 1, 3) && inRange(bPos.y, 4, 6);}

bool checkmate(const Point& r, const Point& b)
{
    bool ans = true;
    switch (board[r.x][r.y])
    {
        case 'G':
            return r.y == b.y && canFly(r, b);
        case 'R':
            return (r.x == b.x || r.y == b.y) && canFly(r, b);
        case 'H':
            for (const auto& HD : HDIRS)
            {
                Point hPos = r + HD, legPos = r + HD / 2;
                if (hPos == b && board[legPos.x][legPos.y] == 0) return true;
            }
            return false;
        case 'C':
            return (r.x == b.x || r.y == b.y) && canFly(r, b, 1);
        default:
            assert(false);
            break;
    }
}

bool canWin()
{
    assert(inBPalace(blackG));
    if (blackG.y == redG.y && canFly(blackG, redG)) return false;
    for (const auto& D : DIRS)
    {
        Point bp = blackG + D;
        if (!inBPalace(bp)) continue;
        char back = board[bp.x][bp.y];
        board[bp.x][bp.y] = 0;
        bool live = true;
        for (const auto& r : redPieces)
        {
            if (board[r.x][r.y] && checkmate(r, bp))
            {
                live = false;
                break;
            }
        }
        board[bp.x][bp.y] = back;
        if (live) return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int N;
    while (scanf("%d%d%d", &N, &(blackG.x), &(blackG.y)) == 3 && N)
    {
        //printf("%d\n", N);
        redPieces.clear();
        memset(board, 0, sizeof(board));
        _for (i, 0, N)
        {
            char type;
            Point p;
           // printf("%d\n", i);
           getchar();
            scanf("%c%d%d", &type, &(p.x), &(p.y));
            redPieces.push_back(p);
            board[p.x][p.y] = type;
            if (type == 'G') redG = p;
            //printf("\n%d", i);
        }
        puts(canWin() ? "YES" : "NO");
    }
    system("pause");
    return 0;
}
