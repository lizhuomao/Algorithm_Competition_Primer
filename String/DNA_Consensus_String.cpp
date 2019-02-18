#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iostream>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _ref(i, a, b) for (int i = (a); j <= (b); ++i)

using namespace std;
struct ChCnt
{
    int cnt;
    char c;
    void init(char ch = 'A') {c = ch; cnt = 0;}
    ChCnt(){init();}
    bool operator < (const ChCnt& cc2) const
    { 
        return cnt > cc2.cnt || (cnt == cc2.cnt && c < cc2.c);
    }
};

const int maxm = 64, maxn = 1024;
const char *DNA = "ACGT";
char seqs[maxm][maxn], IDX[256] = {0};

int main(int argc, char const *argv[])
{
    int T = 1, m, n;
    scanf("%d", &T);
    _for (i, 0, 4) IDX[DNA[i]] = i;
    ChCnt ccs[4];
    while (T--)
    {
        scanf("%d%d", &m, &n);
        _for (i, 0, m)
        {
            getchar();
            fgets(seqs[i], n + 1, stdin);
        }
        int ans = 0;
        _for (i, 0, n)
        {
            _for (j, 0, 4)
            {
                ccs[j].init(DNA[j]);
            }
            _for (j, 0, m)
            {
                ccs[IDX[seqs[j][i]]].cnt++;
            }
            sort(ccs, ccs + 4);
            printf("%c", ccs[0].c);
            ans += (m - ccs[0].cnt);
        }
        printf("\n%d\n", ans);
    }
    system("pause");
    return 0;
}
