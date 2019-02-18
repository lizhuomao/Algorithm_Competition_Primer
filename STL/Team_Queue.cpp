#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

const int maxn = 1000 + 10;

int main(int argc, char const *argv[])
{
    int n, kase = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        printf("Scenario #%d\n", ++kase);
        map<int , int> team;
        for (int i = 0; i < n; i++)
        {
            int k, x;
            scanf("%d", &k);
            while (k--){ scanf("%d", &x); team[x] = i;}
        }
        queue<int> q, q2[maxn];
        for (;;)
        {
            int x;
            string str;
            cin >> str;
            if (str[0] == 'S') break;
            else if (str[0] == 'D')
            {
                int t = q.front();
                printf("%d\n", q2[t].front()); q2[t].pop();
                if (q2[t].empty()) q.pop();
            }
            else if (str[0] == 'E')
            {
                cin >> x;
                int t = team[x];
                if (q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
