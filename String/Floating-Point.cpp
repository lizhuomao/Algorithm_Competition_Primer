#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;

int main(int argc, char const *argv[])
{
    double M[10][31];
    long long  E[10][30];
    _for (i, 0, 10)
    {
        _ref(j, 1, 30)
        {
            double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;
            double t = log10(m) + e * log10(2);
            E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);
        }
    }
    double A;
    int B;
    char line[256];
    while (scanf("%s", line) == 1 && strcmp(line, "0e0") != 0)
    {
        *strchr(line, 'e') = ' ';
        sscanf(line, "%lf%d", &A, &B);
        while (A < 1) A *= 10, B -= 1;
        _for (i, 0, 9)
        {
            _ref (j, 1, 30)
            {
                if (B == E[i][j] && (fabs(M[i][j] - A) < 1e-4 || fabs(M[i][j] - A / 10) < 1e-4))
                {
                    printf("%d %d\n", i, j);
                    break;
                }
            }
        }
    }
    system("pause");
    return 0;
}

