#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
int in_order[maxn], post_order[maxn], lch[maxn], rch[maxn], n;

bool read_int(int* a)
{
    string line;
    if (!getline(cin, line)) return false;
    n = 0;
    int x;
    stringstream ss(line);
    while (ss >> x) a[n++] = x;
    return n > 0;
}

int build(int l1, int r1, int l2, int r2)
{
    if (l1 > r1) return 0;
    int p = l1, root = post_order[r2];
    while (in_order[p] != root) p++;
    int cnt = p - l1;
    lch[root] = build(l1, p - 1, l2, l2 + cnt - 1);
    rch[root] = build(p + 1, r1, l1 + cnt, r2 - 1);
    return root;
}
int best, best_sum;
void dfs(int u, int sum)
{
    sum += u;
    if (!lch[u] && !rch[u])
    {
        if (sum < best_sum || (sum == best_sum && u < best))
        {
            best = u;
            best_sum = sum;
        }
    }
    if (lch[u]) dfs(lch[u], sum);
    if (rch[u]) dfs(rch[u], sum);
}

int main(int argc, char const *argv[])
{
    while (read_int(in_order))
    {
        read_int(post_order);
        build(0, n - 1, 0, n - 1);
        best_sum = 100000;
        dfs(post_order[n - 1], 0);
        printf("%d\n", best);
    }
    return 0;
}
