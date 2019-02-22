#include <cstring>
#include<iostream>
using namespace std;

const int MAX_N = 110;
int c[MAX_N], topo[MAX_N], G[MAX_N][MAX_N], t, N;

bool dfs(int u)
{
    c[u] = -1;
    for (int v = 0; v < N; v++)
    {
        if (G[u][v])
        {
            if (c[v] < 0) return false;
            else if (!c[v]) return dfs(v);
        }
    }
    c[u] = 1;
    topo[--t] = u;
    return true;
}
bool toposort()
{
    t = N;
    memset(c, 0, sizeof(c));
    for (int u = 0; u < N; u++)
    {
        if (!c[u])
        {
            if (!dfs(u)) return false;
        }
    }
    return true;
}

int main(void)
{
    int M;
    scanf("%d%d", &N, &M);
    memset(G, 0, sizeof(G));
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }
    if (toposort())
    {
        for (int i = 0; i < N; i++)
        {
            cout << topo[i] << endl;
        }
    }
    else 
        cout << "No" << endl;
    system("pause");
    return 0;
}