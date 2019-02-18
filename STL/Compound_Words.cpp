#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    set<string> words;
    string word, left, right;
    while (cin >> word) words.insert(word);
    for (const auto& s : words)
    {
        for (int i = 0; i < s.size(); i++)
        {
            left.assign(s, 0, i);
            if (words.count(left))
            {
                right.assign(s, i, s.size() - i);
                if (words.count(right))
                {
                    cout << s << endl;
                    break;
                }
            }
        }
    }
    system("pause");
    return 0;
}
