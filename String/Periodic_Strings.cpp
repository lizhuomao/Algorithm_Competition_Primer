#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 80

int main(int argc, char const *argv[])
{
    char str[maxn];
    scanf("%s", str);
    int count = 1;
    int n = strlen(str);
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            int flag = 0;
            for (int j = i; j < n; j++)
            {
                if (str[j] != str[j % i])
                {
                    flag  = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("%d", i);
                break;
            }
        }
    }
    system("pause");
    return 0;
}
