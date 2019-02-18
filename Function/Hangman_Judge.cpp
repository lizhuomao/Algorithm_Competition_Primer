#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 100
#define _for(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

char s[maxn], s1[maxn];
int left, chance, win, lose;

void guess(char ch)
{
    int bad = 1;
    _for(i, 0, strlen(s))
    {
        if (s[i] == ch)
        {
            left--;
            s[i] = ' ';
            bad = 0;
        }
    }
    if (bad) chance--;
    if (!chance) lose = 1;
    if (!left) win = 1;
    return;
}

int main(int argc, char const *argv[])
{
    int cnt;
    while (scanf("%d%s%s", &cnt, s, s1) == 3 && cnt != -1)
    {
        printf("Round %d\n", cnt);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        _for (i, 0, strlen(s1))
        {
            guess(s1[i]);
            if (win || lose)
            {
                break;
            }
        }
        if (win) printf("You win.\n");
        else if (lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    system("pause");
    return 0;
}
