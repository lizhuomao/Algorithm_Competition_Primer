#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node
{
    char value;
    node *left, *right;
};
char per[256], in[256], pos[256];

node *buildtree(int root, int start, int end)
{
    if (start > end) return NULL;
    int i = start;
    while (i < end && in[i] != per[root]) i++;
    node *t = new node();
    //cout << i << " " << root << " " << start << " " << end << " " << in[i] << " " << per[root] << endl;
    t -> value = per[root];
    t -> left = buildtree(root + 1, start, i - 1);
    t -> right = buildtree(root + (i - start) + 1, i + 1, end);
    return t;
}
void pos_order(node *t)
{
    if (t == NULL) return;
    pos_order(t -> left);
    pos_order(t -> right);
    cout << t -> value;
}

int main(void)
{
    while (cin >> per >> in)
    {
        node *t = buildtree(0, 0, strlen(in) - 1);
        pos_order(t);
        cout << endl;
    }
    system("pause");
    return 0;
}