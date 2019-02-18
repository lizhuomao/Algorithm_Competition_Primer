#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 105

int less(const char* s, int p, int q)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[(p + i) % n] != s[(q + i) % n])
        {
            return s[(p + i) % n] < s[(q + i) % n];
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int ans = 0;
        int n = strlen(s);
        for (int i = 1; i < n; i++)
        {
            if (less(s, i, ans))
            {
                ans = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%c", s[(ans + i) % n]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

