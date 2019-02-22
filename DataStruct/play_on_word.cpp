#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int cases, n, x, y, P[2][26], par[26], temp;
bool visit[26];
string str;

void init(int N)
{
    for (int i = 0; i < N; i++)
    {
        par[i] = i;
    }
}
int find(int x)
{
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    par[x] = y;
}

int main(void)
{
    cin >> cases;
    while (cases--)
    {
        cin >> n;
        memset(visit, false, sizeof(visit));
        memset(P, 0, sizeof(P));
        init(26);
        for (int i = 1; i <= n; i++)
        {
            cin >> str;
            x = str[0] - 'a';
            y = str[str.size() - 1] - 'a';            
            P[0][x]++;
            P[1][y]++;
            visit[x] = visit[y] = true;
            unite(x, y);
            temp = find(x);
           // cout << x << " " << y << " " << temp << endl;
        }
        if (n == 1)
        {
            cout << "Ordering is possible." << endl;
            continue;
        }
        int i;
        for (i = 0; i < 26; i++)
        {
           // cout << visit[i] << " " << find(i) << endl;
            if (visit[i] && find(i) != temp) break;
        }
        if (i < 26)
        {
            cout << "The door cannot be opened." << endl;
            continue;
        }
        int t1 = 0, t2 = 0;
        for (i = 0; i < 26; i++)
        {
            if (P[0][i] == P[1][i]) continue;
            if (P[0][i] + 1 == P[1][i]) t1++;
            else if (P[1][i] + 1 == P[0][i]) t2++;
            else break;
        }
        if (i < 26 || !(t1 == 1 && t2 == 1 || !t1 && !t2))
            cout << "The door cannot be opened." << endl;
        else
            cout << "Ordering is possible." << endl;
    }
    system("pause");
    return 0;
}