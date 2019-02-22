#include <cstring>
#include <iostream>
using namespace std;

const int MAX_N = 200 + 10;
char buf[MAX_N][MAX_N];
int T, n;

void dfs(int r, int c)
{
    cout << buf[r][c] << "(";
    if (r + 1 < n && buf[r + 1][c] == '|')
    {
        int i = c;
        while (i - 1 >= 0 && buf[r + 2][i - 1] == '-') i--;
        while (buf[r + 2][i] == '-' && buf[r + 3][i] != '\0')
        {
            if (!isspace(buf[r + 3][i])) dfs(r + 3, i);
            i++;
        }
    }
    cout << ")";
    return;
}
void solve()
{
    n = 0;
    while (true)
    {
        fgets(buf[n], MAX_N, stdin);
        if (buf[n][0] == '#') break;
        else n++;
    }
    cout << "(";
    if (n)
    {
        for (int i = 0; i < strlen(buf[0]); i++)
        {
            if (buf[0][i] != ' ')
            {
                dfs(0, i);
                break;
            }
        }
    }
    cout << ")" << endl;
    return;
}

int main(void)
{
    int T;
    fgets(buf[0], MAX_N, stdin);
    sscanf(buf[0], "%d", &T);
    while (T--) solve();
    system("pause");
    return 0;
}