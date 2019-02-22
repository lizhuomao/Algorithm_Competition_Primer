#include <iostream>
using namespace std;

int main(void)
{
    char buf[1 << 8], T[1 << 8], V[8];
    int n, m, t, dx[8];
    for(t = 0; scanf("%d", &n) && n; t++)
    {
        cout << "S-Tree #" << t << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> buf;
            dx[i] = buf[1] - '1';
        }
        cin >> T >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> V;
            int d = 0, u = 1;
            while (d < n) u = 2 * u + (V[dx[d++]] - '0');
            cout << T[u - (1 << n)];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}