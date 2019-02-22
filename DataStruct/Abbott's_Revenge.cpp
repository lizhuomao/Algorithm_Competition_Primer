#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const char *dirs = "NESW", *turns = "FLR";
const int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1}, MAX_N = 10;
struct node
{
    int r, c, dir;
};
int has_edge[MAX_N][MAX_N][4][3], d[MAX_N][MAX_N][4], r0, c0, r1, c1, r2, c2, dir;
node p[MAX_N][MAX_N][4];
string maze_name;

int dir_id(char c)
{
    return strchr(dirs, c) - dirs;
}
int turn_id(char c)
{
    return strchr(turns, c) - turns;
}
node walk(const node &u, int turn)
{
    int dir = u.dir;
    if (turn == 1) dir = (dir + 3) % 4;
    if (turn == 2) dir = (dir + 1) % 4;
    return node{u.r + dr[dir], u.c + dc[dir], dir};
}
bool inside(int r, int c)
{
    if (r >= 1 && r <= 9 && c >= 1 && c <= 9)
    {
        return true;
    }
    return false;
}
void print_ans(node u)
{
    vector<node> nodes;
    for (;;)
    {
        nodes.push_back(u);
        if (d[u.r][u.c][u.dir] == 0) break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back(node{r0, c0, dir});
    int cnt = 0;
    for (int i = nodes.size() - 1; i >= 0; i--)
    {
        if (cnt % 10 == 0) cout << " ";
        cout << "(" << nodes[i].r << "," << nodes[i].c << ")";
        if (++cnt % 10 == 0) cout << endl;
    }
    if (nodes.size() % 10 != 0) cout << endl;
    return;
}
void solve()
{
    queue<node> q;
    memset(d, -1, sizeof(d));
    node n1{r1, c1, dir};
    q.push(n1);
    d[r1][c1][dir] = 0;
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        if (u.r == r2 && u.c == c2)
        {
            print_ans(u);
            return;
        }
        for (int i = 0; i < 3; i++)
        {
            node v = walk(u, i);
            if (has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0)
            {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    cout << "No Solution Possible" << endl;
    return;
}
bool read_case() 
{
    char s[99], s2[99];
    if(scanf("%d%d%s%d%d", &r0, &c0, s2, &r2, &c2) != 5) return false;
    dir = dir_id(s2[0]);
    r1 = r0 + dr[dir];
    c1 = c0 + dc[dir];
    memset(has_edge, 0, sizeof(has_edge));
    for(;;) 
    {
        int r, c;
        scanf("%d", &r);
        if(r == 0) break;
        scanf("%d", &c);
        while(scanf("%s", s) == 1 && s[0] != '*') 
        {
            for(int i = 1; i < strlen(s); i++)
                has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
        }
    }
    return true;
}

int main(void)
{
    while (read_case())
    {
        solve();
    }
    system("pause");
    return 0;
}