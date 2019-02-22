#include <cstring>
#include <stack>
#include <iostream>
using namespace std;

const int MAX_N = 256;
int n;
char buf[MAX_N];

bool solve()
{
    stack<int> s;
    cin >> buf;
    for(int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] == '(' || buf[i] == '[') s.push(buf[i]);
        else
        {
            if (s.empty()) return false;
            int c = s.top();
            if (buf[i] == ')')
            {
                if (c == '(') s.pop();
                else break;
            }
            else if (buf[i] == ']')
            {
                if (c == '[') s.pop();
                else break;
            }
        }
    }
    return s.empty();
}

int main(void)
{
    cin >> n;
    while (n--)
    {
        if (solve()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    system("pause");
    return 0;
}