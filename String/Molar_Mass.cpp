#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxn 100

float msg[] = {12.01f, 1.008f, 16.00f, 14.01f};
char  ch[] = {'C', 'H', 'O', 'N'};
int main(int argc, char const *argv[])
{
    int N;
    char s[maxn];
    scanf("%d", &N);
    while (N--)
    {
        scanf("%s", s);
        printf("%s", s);
        int n = strlen(s);
        float sum = 0.0f;
        for (int i = 0; i < 4; i++)
        {
            if (s[n - 1] == ch[i])
            {
               // printf ("s[n - 1] = %c, ch[i] = %c", s[n - 1], ch[i]);
                sum = msg[i];
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            //printf("%c", s[i]);
            if (isalpha(s[i]))
            {
                if (isdigit(s[i + 1]))
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (s[i] == ch[j])
                        {
                            int temp = s[i + 1] - '0';
                           // printf(" %d ", temp);
                            sum = sum + msg[j] * temp;
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (s[i] == ch[j])
                        {
                            sum += msg[j]; 
                        }
                    }
                }
            }
            //printf("%f\n", sum);
        }
        //printf("%f\n", sum);
    }
    system("pause");
    return 0;
}
