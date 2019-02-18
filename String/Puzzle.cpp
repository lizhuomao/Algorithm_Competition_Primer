#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    char s[5][5];
    char ch = getchar();
    int kase = 1;
    while (ch != 'Z')
    {
        int col, row, solv = 1;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                s[i][j] = ch;
                if (s[i][j] == ' ')
                {
                    row = i;
                    col = j;
                }
                ch = getchar();
            }
            ch = getchar();
        }
        while (ch != '0')
        {
            if (ch == 'A' && row - 1 >= 0)
            {
                s[row--][col] = s[row][col];
            }
            else if (ch == 'B' && row + 1 < 5)
            {
                s[row++][col] = s[row][col];
            }
            else if (ch == 'L' && col - 1 >= 0)
            {
                s[row][col--] = s[row][col];
            }
            else if (ch == 'R' && col + 1 < 5)
            {
                s[row][col++] = s[row][col];
            }
            else
            {
                solv = 0;
            }
            s[row][col] = ' ';
            ch = getchar();
        }
        ch = getchar();
        while (ch == '\n')
        {
            ch = getchar();
        }
        if (kase > 1)
        {
            printf("\n");
        }
        printf("Puzzle #%d\n", kase++);
        if (!solv)
        {
            printf("This puzzle has no final configuration.\n");
            continue;
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                putchar(s[i][j]);
                if (j == 4)
                {
                    putchar('\n');
                }
                else
                {
                    putchar(' ');
                }
            }
        }
    }
    system("pause");
    return 0;
}
