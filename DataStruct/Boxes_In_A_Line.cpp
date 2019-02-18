#include <iostream>
using namespace std;
const int maxn = 10000 + 5;
int n, Left[maxn], Right[maxn];

inline void link(int L, int R)
{
    Right[L] = R;
    Left[R] = L;
}

int main(int argc, char const *argv[])
{
    int m , kase = 0;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
        {
            Left[i] = i - 1;
            Right[i] = (i + 1) % (n + 1);
        }
        Left[0] = n;
        Right[n] = 1;
        int op, x, y, inv = 0;
        while(m--)
        {
            scanf("%d", &op);
            if (op == 4) inv = !inv;
            else 
            {
                scanf("%d%d", &x, &y);
                if (op == 3 && Right[y] == x) swap(x, y);
                if (op != 3 && inv) op = 3 - op;
                if (op == 1 && x == Left[y]) continue;
                if (op == 2 && x == Right[y]) continue;
                int Lx = Left[x], Rx = Right[x], Ly = Left[y], Ry = Right[y];
                if (op == 1)
                {
                    link(Lx, Rx); link(Ly, x); link(x, y);
                }
                else if (op == 2)
                {
                    link(Lx, Rx); link(x, Ry); link(y, x);
                }
                else if (op == 3)
                {
                    if (Right[x] == y) 
                    { 
                        link(Lx, y); link(y, x); link(x, Ry);
                    }
                    else
                    {
                        link(Lx, y); link(y, Rx); link(Ly, x); link(x, Ry);
                    }
                }
            }
        }
        int b = 0;
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            b = Right[b];
            if (i % 2 == 1) ans += b;
        }
        if (inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans;
        printf("Case %d: %lld\n", ++kase, ans);
    }
    system("pause");
    return 0;
}