#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
struct arrayinfo
{
    map<int, int> data;
    size_t length;
    arrayinfo(size_t len) : length(len) {};
};
arrayinfo* arrayset[256] = {0};
int exeline = 0;
int getvalue (const string& exp)
{
    if (exp[0] >= '0' && exp[0] <= '9') return atoi(exp.c_str());
    size_t begin = exp.find('[');
    int id = getvalue(exp.substr(begin + 1, exp.length() - begin - 2));
    if (id == -1) return -1;
    if (id >= arrayset[exp[0]] -> length)
    {
        cout << exeline << endl;
        return -1;
    }

    map<int, int> :: iterator it = arrayset[exp[0]] -> data.find(id);
    if (it == arrayset[exp[0]] -> data.end())
    {
        cout << exeline << endl;
        return -1;
    }
    return it -> second;
}

int setvalue (const string& exp, int value)
{
    size_t begin = exp.find('[');
    int id = getvalue(exp.substr(begin + 1, exp.length() - begin - 2));
    if (id == -1) return -1;
    if (id >= arrayset[exp[0]] -> length)
    {
        cout << exeline << endl;
        return -1;
    }
    map<int, int> :: iterator it = arrayset[exp[0]] -> data.find(id);
    if (it == arrayset[exp[0]] -> data.end()) arrayset[exp[0]] -> data.insert(pair<int, int>(id, value));
    else it -> second = value;
    return 0;
}

int eval(const string& str)
{
    arrayinfo* tmparray;
    if (arrayset[str[0]] == 0)
    {
        tmparray = new arrayinfo(atoi(str.c_str() + 2));
        arrayset[str[0]] = tmparray;
    }
    else
    {
        size_t aoffset = str.find('=');
        int r = getvalue(str.substr(aoffset + 1, str.length() - aoffset));
        if (r == -1) return -1;
        return setvalue(str.substr(0, aoffset), r);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    string line;
    int err = 0;
    bool sdot = false;
    while (cin >> line)
    {
        if (line[0] == '.')
        {
        Clear:
            if (sdot == true)
                break;
            sdot = true;
            for (int i = 0; i < 256; i++)
            {
                if (arrayset[i] != 0) {delete arrayset[i]; arrayset[i] = 0;}
            }
            exeline = 0;
            if (err != -1) cout << "0" << endl;
            continue;
        }
        sdot = false;
        ++exeline;
        err = eval(line);
        if (err == -1)
        {
            for (;;)
            {
                cin >> line;
                if (line[0] == '.') goto Clear;
            }
        }
    }
    system("pause");
    return 0;
}
