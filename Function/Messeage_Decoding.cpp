#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;

int readchar()
{
    for (;;)
    {
        int ch = getchar();
        if (ch != '\n' && ch != '\r') return ch;
    }
}
int readint(int c)
{
    int v = 0;
    while (c--) v = v * 2 + readchar() - '0';
    return v;
}
int code[8][1 << 8];
int readcodes()
{
    memset(code, 0, sizeof(code));
    code[1][0] = readchar();
    _ref(len, 2, 7)
    {
        _for (i, 0, (1 << len) - 1)
        {
            int ch = getchar();
            if (ch == EOF) return 0;
            if (ch == '\n' || ch == '\r') return 1;
            code[len][i] = ch;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    while (readcodes())
    {
        for (;;)
        {
            int len = readint(3);
            if (len == 0) break;
            for (;;)
            {
                int v = readint(len);
                if (v == (1 << len) - 1) break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    system("pause");
    return 0;
}
