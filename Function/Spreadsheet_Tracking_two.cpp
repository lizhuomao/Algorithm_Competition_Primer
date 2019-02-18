#include <stdio.h>
#include <stdlib.h>
#define maxn 10000
#define _for(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
int r, c, n;
struct Command
{
    char c[5];
    int r1, c1, r2, c2;
    int a, x[20];
} cmd[maxn];

int simulate(int* r0, int* c0)
{
    _for (i, 0, n)
    {
        if (cmd[i].c[0] == 'E')
        {
            if (cmd[i].r1 == *r0 && cmd[i].c1 == *c0)
            {
                *r0 = cmd[i].r2;
                *c0 = cmd[i].c2;
            }
            else if (cmd[i].r2 == *r0 && cmd[i].c2 == *c0)
            {
                *r0 = cmd[i].r1;
                *c0 = cmd[i].c1;
            }
        }
        else
        {
            int dr = 0, dc = 0;
            _for (j, 0, cmd[i].a)
            {
                int x = cmd[i].x[j];
                if (cmd[i].c[0] == 'I')
                {
                    if (cmd[i].c[1] == 'R' && x <= *r0) dr++;
                    if (cmd[i].c[1] == 'C' && x <= *c0) dc++;
                }
                else
                {
                    if (cmd[i].c[1] == 'R' && x == *r0) return 0;
                    if (cmd[i].c[1] == 'C' && x == *c0) return 0;
                    if (cmd[i].c[1] == 'R' && x < *r0) dr--;
                    if (cmd[i].c[1] == 'C' && x < *c0) dc--;
                }
            }
            *r0 += dr;
            *c0 += dc;
        }
    }
     return 1;
}

int main(int argc, char const *argv[])
{
    int r0, c0, q, kase = 0;
    while (scanf("%d%d%d", &r, &c, &n) == 3 && r)
    {
        _for (i, 0, n)
        {
            scanf("%s", cmd[i].c);
            if (cmd[i].c[0] == 'E')
            {
                scanf("%d%d%d%d", &cmd[i].r1, &cmd[i].c1, &cmd[i].r2, &cmd[i].c2);
            }
            else
            {
                scanf("%d", &cmd[i].a);
                _for (j, 0, cmd[i].a) scanf("%d", &cmd[i].x[j]);
            }
        }
        if (kase > 0) printf("\n");
        printf("Spreadsheet #%d\n", ++kase);

        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &r0, &c0);
            printf("Cell data in (%d,%d) ", r0, c0);
            if (!simulate(&r0, &c0)) printf("GONE\n");
            else printf("moved to (%d,%d)\n", r0, c0);
        }
    }
    system("pause");
    return 0;
}
