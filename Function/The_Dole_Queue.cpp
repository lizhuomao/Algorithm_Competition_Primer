#include <stdio.h>
#include <stdlib.h>
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)
#define maxn 25
int a[maxn], n, k, m;
using namespace std;

int go (int p, int d, int t)
{
    while (t--)
    {
        do
        {
            p = (p + d + n - 1) % n + 1;
        }while (a[p] == 0);
    }
    return p;
}

int main(int argc, char const *argv[])
{
    while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
    {
        _ref(i, 1, n) a[i] = i;
        int left = n, p1 = 1, p2 = n;
        while (left)
        {
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", p1);
            left--;
            if (p1 != p2)
            {
                printf("%3d", p2);
                left--;
            }
            a[p1] = a[p2] = 0;
            if (left) printf(",");
        }
        printf("\n");
    }
    return 0;
}
