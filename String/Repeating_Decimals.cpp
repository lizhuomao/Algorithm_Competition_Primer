#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

const int maxn = 30000 + 5;
int res[maxn], arr[maxn], v[maxn];

int main(int argc, char const *argv[])
{
    memset(res, 0, sizeof(res));
    int a, b, cnt = 1;
    scanf("%d%d", &a, &b);
    a = a % b * 10;
    while (res[a] == 0)
    {
        res[a] = 1;
        v[a] = cnt;
        arr[cnt++] = a / b;
        a = a % b * 10;
    }
    printf("%d %d\n", v[a], cnt);
    printf("%d\n", cnt - v[a]);
    for (int i = v[a]; i < cnt; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
