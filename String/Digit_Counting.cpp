#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int count[10];
    memset(count, 0, sizeof(count));
    for (int i = 1; i <= n; i++)
    {
        int temp = i;
        while (temp)
        {
            int x = temp % 10;
            count[x]++;
            temp /= 10;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", count[i]);
    }
    system("pause");
    return 0;
}
