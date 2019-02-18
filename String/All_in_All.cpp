#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _ref(i, a, b) for (int i = (a); i <= (b); ++i)

using namespace std;

int main(int argc, char const *argv[])
{
    string s, t;
    cin >> s >> t;
    int j = 0;
    _for (i, 0, s.size())
    {
        if (t[j] == s[i])
        {
            j++;
        }
    }
    j == t.size() ? printf("yes") : printf("no");
    system("pause");
    return 0;
}
