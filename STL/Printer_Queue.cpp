#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int maxn = 10, maxc = 128;
int cnt[maxn], pri[maxc];

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        memset(pri, 0, sizeof(pri));
        int n, m;
        scanf("%d%d", &n, &m);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            q.push(i);
            int temp;
            scanf("%d", &temp);
            cnt[temp]++;
            pri[i] = temp;
        }
        int time_ = 1;
        while (!q.empty())
        {
            //cout << "Debug";
            int t = q.front();
            int p = pri[t];
            bool flag = false;
            for (int i = maxn - 1; i > p; i--)
            {
                if (cnt[i] > 0) { flag = true; break;}
            }
            q.pop();
            if (flag)
            {
                q.push(t);
                continue;
            }
            if (t == m) break;
            cnt[p]--;
            time_++;
        }
        printf("%d\n", time_);
    }
    system("pause");
    return 0;
}
