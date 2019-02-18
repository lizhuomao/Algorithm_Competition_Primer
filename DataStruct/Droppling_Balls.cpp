#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn = 20;
int s[1 << maxn];

int main(int argc, char const *argv[])
{
    int D, I;
    // while (scanf("%d%d", &D, &I) == 2)
    // {
    //     int n = 1 << D - 1;
    //     int k;
    //     memset(s, 0, sizeof(s));
    //     for (int i = 0; i < I; i++)
    //     {
    //         k = 1;
    //         while (true)
    //         {
    //             s[k] = !s[k];
    //             k = s[k] ? k * 2 : k * 2 + 1;
    //             if (k > n) break;
    //         }
    //     }
    //     printf("%d\n", k / 2);
    // }
    while (scanf("%d%d", &D, &I) == 2)
    {
        int k = 1;
        for (int i = 0; i < D - 1; i++)
        {
            if (I % 2) { k = k * 2; I = (I + 1) / 2;}
            else { k = k * 2 + 1; I /= 2;}
        }
        printf("%d\n", k);
    }
    system("pause");
    return 0;
}
