#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxc = 180 + 5, maxr = 1000 + 5;
vector<string> Code[maxr];
int Max[maxc];
int scnt;

void print(const string& s, int len, char extra)
{
    cout << s;
    for (int i = 0; i < len - s.size(); i++) cout << extra;
}

int main(int argc, char const *argv[])
{
     string temp;
    memset(Max, 0, sizeof(Max));
    int cnt = 0;
    while (getline(cin, temp))
    {
        stringstream ss(temp);
        string word;
        int count = 0;
        while (ss >> word)
        {
            Max[count] = max(Max[count], (int)word.size());
            Code[cnt].push_back(word);
            count++;
        }
        cnt++;
    }

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < Code[i].size(); j++)
        {
            //int c = Code[i][j].size();
            print(Code[i][j], j == Code[i].size() - 1 ? Code[i][j].size() : Max[j] + 1, ' ');
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
