#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxd 100
#define BIG 10000
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)

int r, c, n, d[maxd][maxd], d2[maxd][maxd], ans[maxd][maxd], cols[maxd];

void copy(char type, int p, int q)
{
    if (type == 'R')
    {
        _ref(i, 1, c)
        {
            d[p][i] = d2[q][i];
        }
    }
    else
    {
        _ref(i, 1, r)
        {
            d[i][p] = d2[i][q];
        }
    }
}

void del(char type)
{
    memcpy(d2, d, sizeof(d));
    int cnt = type  == 'R' ? r : c, cnt2 = 0;
    _ref(i, 1, cnt)
    {
        if (!cols[i]) copy(type, ++cnt2, i);
    }
    if (type == 'R') r = cnt2;
    else c = cnt2;
}

void ins(char type)
{
    memcpy(d2, d, sizeof(d));
    int cnt = type == 'R' ? r : c, cnt2 = 0;
    _ref(i, 1, cnt)
    {
        if (cols[i]) copy(type, ++cnt2, 0);
        copy(type, ++cnt2, i);
    }
    if (type == 'R') r = cnt2; else c = cnt2;
}

int main()
{
    int r1, c1, r2, c2, q, kase = 0;
    char cmd[10];
    memset(d, 0, sizeof(d));
    while (scanf("%d%d%d", &r, &c, &n) == 3 && r)
    {
        int r0 = r, c0 = c;
        _ref(i, 1, r)
        {
            _ref(j, 1, c)
            {
                d[i][j] = i * BIG + j;
            }
        }
        while (n--)
        {
            scanf("%s", cmd);
            if (cmd[0] == 'E')
            {
                scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
                int t = d[r1][c1];
                d[r1][c1] = d[r2][c2];
                d[r2][c2] = t;
            }
            else
            {
                int a, x;
                scanf("%d", &a);
                memset(cols, 0, sizeof(cols));
                _for (i, 0, a)
                {
                    scanf("%d", &x);
                    cols[x] = 1;
                }
                if (cmd[0] == 'D')
                {
                    del(cmd[1]);
                }
                else
                {
                    ins(cmd[1]);
                }
            }
        }
        memset(ans, 0, sizeof(ans));
        _ref(i, 1, r)
        {
            _ref(j, 1, c)
            {
                ans[d[i][j] / BIG][d[i][j] % BIG] = i * BIG + j;
            }
        }
        if (kase > 0) printf("\n");
        printf("Spreadsheet #%d\n", ++kase);
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &r1, &c1);
            printf("Cell data in (%d,%d)", r1, c1);
            if (ans[r1][c1] == 0) printf("GONE\n");
            else printf("moved to (%d,%d)\n", ans[r1][c1] / BIG, ans[r1][c1] % BIG);
        }
    }
    system("pause");
    return 0;
} 