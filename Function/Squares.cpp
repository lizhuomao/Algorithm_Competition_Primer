#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxn 11
#define _for(i, a, b) for (int i = (a); i < (b); i++)
#define _ref(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
int H[maxn][maxn], V[maxn][maxn];

int main(int argc, char const *argv[])
{
    int n, m;
    for (int t = 1; scanf("%d", &n) == 1; t++)
    {
        if (t > 1) printf("\n**********************************\n\n");
        scanf("%d", &m);
        getchar();
        _ref (i, 1, n)
        {
            _ref (j, 1, n)
            {
                V[i][j] = H[i][j] = 0;
            }
        }
        char c;
        int x, y;
        _ref(i, 1, m)
        {
            scanf("%c%d%d", &c, &x, &y);
            //printf("\nc = %c", c);
            getchar();
            if (c == 'H')
            {
                H[x][y] = 1;
            }
            else
            {
                V[y][x] = 1;
            }
        }
        printf("Problem #%d\n\n", t);
        int sum = 0;
		for (int l = 1 ; l <= n ; l++) {
			int count = 0, flag = 0;
			for (int i = 1 ; i + l <= n ; i++)
			for (int j = 1 ; j + l <= n ; j++) {
				flag = 1;
				for (int h = j ; h < j + l ; h++)
					if (!H[i][h] || !H[i+l][h]) flag = 0;
				for (int v = i ; v < i + l ; v++)
					if (!V[v][j] || !V[v][j+l]) flag = 0;
				count += flag;
			}
			sum += count;
			if (count) printf("%d square (s) of size %d\n",count,l);
		}
			
		if (!sum) printf("No completed squares can be found.\n");
    }
    system("pause");
    return 0;
}
