#include <algorithm>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        string line;
        cin >> line;
        int depth = 0, nodeCnt = 0;
        map<long long, int> vCnt;
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '[') depth++;
            else if (line[i] == ']') depth--;
            else if (isdigit(line[i]))
            {
                int j;
                long long v = line[i] - '0';
                for (j = i + 1; j < line.size() && isdigit(line[j]); j++)
                {
                    v *= 10;
                    v += line[j] - '0';
                }
                i = j - 1;
                v <<= depth;
                vCnt[v]++;
                nodeCnt++;
            }
        }
        int k = -1;
        for (const auto &p : vCnt)
        {
            k = max(k, p.second);
        }
        cout << nodeCnt - k << endl;
    }
    system("pause");
    return 0;
}