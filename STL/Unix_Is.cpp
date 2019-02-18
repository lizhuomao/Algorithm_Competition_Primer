#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxcol = 60;
const int maxn = 100 + 5;
string filename[maxn];

void print(const string& s, int len, char extra)
{
    cout << s;
    for (int i = 0; i < len - s.length(); i++)
    {
        cout << extra;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    while (cin >> n)
    {
        int M = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> filename[i];
            M = max(M, (int)filename[i].length());
        }
        int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
        print("", 60, '-');
        cout << "\n";
        sort(filename, filename + n);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int idx = c * rows + r;
                if (idx < n) print(filename[idx], c == cols - 1 ? M : M + 2, ' ');
            }
            cout << "\n";
        }
    }
    system("pause");
    return 0;
}
