#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 100005
int ans[maxn];

int main(int argc, char const *argv[])
{
    int T, n;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i < maxn; i++)
    {
        int x = i, y = i;
        while(x)
        {
            y += x % 10;
            x = x / 10;
        }
        if (ans[y] == 0 || ans[y] > i)
        {
            ans[y] = i;
        }
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    system("pause");
    return 0;
}
