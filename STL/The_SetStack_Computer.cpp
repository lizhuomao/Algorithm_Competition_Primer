#include <algorithm>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iterator>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin() )
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set> Setcache;
int t, n;
int ID(Set x)
{
    if (IDcache.count(x)) return IDcache[x];
    Setcache.push_back(x);
    return IDcache[x] = Setcache.size() - 1;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        stack<int > s;
        while (n--)
        {
            string str;
            cin >> str;
            if (str[0] == 'P') s.push(ID(Set()));
            else if (str[0] == 'D') s.push(s.top());
            else
            {
                Set s1 = Setcache[s.top()]; s.pop();
                Set s2 = Setcache[s.top()]; s.pop();
                Set x;
                if (str[0] == 'U') set_union(ALL(s1), ALL(s2), INS(x));
                if (str[0] == 'I') set_intersection(ALL(s1), ALL(s2), INS(x));
                if (str[0] == 'A') {x = s2; x.insert(ID(s1));}
                s.push(ID(x));
            }
            printf("%d\n", Setcache[s.top()].size());
        }
        puts("***");
    }
    system("pause");
    return 0;
}
