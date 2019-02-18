#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 81

int main(int argc, char const *argv[])
{
    char s[maxn];
    int N;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", s);
        int n = strlen(s);
        int p = 0, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'O')
            {
                p++;
            }
            else if (s[i] == 'X')
            {
                p = 0;
            }
            sum += p;
        }
        printf("%d\n", sum);
    }
    system("pause");
    return 0;
}
