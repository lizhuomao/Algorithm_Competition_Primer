#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)
const int W = 8, IPW = 4 * W, MAXN = 1024;
int ips[MAXN][IPW + 4];
using namespace std;

void printIP(const int* v)
{
    bool first = true;
    _for (i, 0, 4)
    {
        int x = 0;
        _for (j, i * W, (i + 1) * W) x = (x << 1) | v[j];
        if (first) first = false; else printf(".");
        printf("%d", x);
    }
    puts("");
}

void to_Binary(int x, int *v, int pos)
{
    _for (i, 0, W) v[pos + W - i - 1] = x % 2, x /= 2;
}

int main(int argc, char const *argv[])
{
    int m, ip[4], subNet[IPW];
    while (scanf("%d", &m) == 1)
    {
        memset(subNet, 0, sizeof(subNet));
        _for (i, 0, m)
        {
            scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
            _for(j, 0, 4) to_Binary(ip[j], ips[i], j * W);
        }
        int n;
        for (n = 0; n < IPW; n++)
        {
            bool same = true;
            _for (j, 1, m) if (ips[j][n] != ips[j - 1][n]) { same = false; break;}
            if (!same) break;
        }
        fill_n(subNet, n, 1);
        fill_n(ips[0] + n, IPW - n, 0);
        printIP(ips[0]);
        printIP(subNet);
    }
    system("pause");
    return 0;
}
