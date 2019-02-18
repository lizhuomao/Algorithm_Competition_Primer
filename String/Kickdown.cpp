#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define maxn 100
#define _for(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

int n1, n2;
int minLen(char *s1, char *s2, int &n)
{
    int sumlen = n1 + n2, minlen = __min(n1, n2), len = sumlen;
    _for (i, 0, n)
    {
        int ok = 1, cnt = __min(minlen, n - i);
        _for (j, 0, cnt)
        {
            if (s1[j + i] == '2' && s2[j] == '2')
            {
                ok = 0;
                break;
            }
        }
        if (ok && len > sumlen - cnt) len = sumlen - cnt;
    }
    return len;
}

int main(int argc, char const *argv[])
{
    char a[maxn], b[maxn];
    while (scanf("%s%s", &a, &b) == 2)
    {
        n1 = strlen(a), n2 = strlen(b);
        printf("%d\n", __min(minLen(a, b, n1), minLen(b, a, n2)));
    }
    system("pause");
    return 0;
}
