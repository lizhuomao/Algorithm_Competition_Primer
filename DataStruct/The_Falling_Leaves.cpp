#include <iostream>
#include <string.h>
using namespace std;

const int maxn = 10000 + 10;
int sum[maxn];

void build(int p)
{
    int v;
    cin >> v;
    if (v == -1) return;
    sum[p] += v;
    build(p - 1);
    build(p + 1);
}

bool init()
{
    int v;
    cin >> v;
    if (v == -1) return false;
    memset(sum, 0, sizeof(sum));
    int p = maxn / 2;
    sum[p] = v;
    build(p - 1);
    build(p + 1);
}

int main(int argc, char const *argv[])
{
    while (init())
    {
        int p = 0;
        while (sum[p] == 0) p++;
        int kase = 0;
        cout << "Case " << ++kase << ":\n" << sum[p++];
        while (sum[p] != 0) cout << " " << sum[p++];
        cout << "\n\n";
    }
    system("pause");
    return 0;
}
