#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>
using namespace std;

set<int> emptyIntset;
struct Doc
{
    set<int> lines;
    map<string, set<int>> words;
    void AddLine(const string& s, int l)
    {
        lines.insert(l);
        string w;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (isalpha(c)) w.push_back(tolower(c));
            else if (!w.empty()) { words[w].insert(l); w.clear();}
        }
        if (!w.empty()) words[w].insert(l);
    }
    const set<int>& FindWord(const string& w)
    {
        if (!words.count(w)) return emptyIntset;
        return words[w];
    }
};

vector <Doc> docs;
vector <string> Lines;

ostream& operator << (ostream& os, const set<int>& lines)
{
    for (set<int> :: const_iterator it = lines.begin(); it != lines.end(); it++)
    {
        os << Lines[*it] << endl;
    }
    return os;
}

void parseQuery(const string& q, vector<string>& ws)
{
    ws.clear();
    stringstream ss(q);
    string w;
    while (ss >> w) ws.push_back(w);
}

void doQuery(const vector<string>& qWs)
{
    const string& A = qWs.front();
    const string& B = qWs.back();
    bool isAnd = (qWs.size() == 3 && qWs[1] == "AND"), first = true, match;
    stringstream ss;
    switch(qWs.size())
    {
        case 1:
            for (int i = 0; i < docs.size(); i++)
            {
                Doc& a = docs[i];
                const set<int>& ans = a.FindWord(A);
                match = !ans.empty();
                if (!match) continue;
                if (first) first = false; else ss << "----------" << endl;
                ss << ans;
            }
            break;
        case 2:
            for (int i = 0; i < docs.size(); i++)
            {
                Doc& a = docs[i];
                const set<int>& ans = a.FindWord(B);
                match = ans.empty();
                if (!match) continue;
                if (first) first = false; else ss << "----------" << endl;
                ss << a.lines;
            }
            break;
            
        case 3:
            for (int i = 0; i < docs.size(); i++)
            {
                Doc& a = docs[i];
                const set<int>& ansA = a.FindWord(A);
                const set<int>& ansB = a.FindWord(B);
                if (isAnd) match = (!ansA.empty() && !ansB.empty());
                else match = (!ansA.empty() || !ansB.empty());
                if (!match) continue;
                vector<int> ans(ansA.size() + ansB.size());
                vector<int> :: iterator st = set_union(ansA.begin(), ansA.end(), ansB.begin(), ansB.end(), ans.begin());
                if (first) first = false; else cout << "----------" << endl;
                for (vector<int> :: iterator it = ans.begin(); it != st; it++)
                {
                    ss << Lines[*it] << endl;
                }
            }
            break;
        default:
            break;
    }
    const string& output = ss.str();
    if (output.empty()) cout << "Sorry, I found nothing." << endl;
    cout << output << "==========" << endl;
}

int main(int argc, char const *argv[])
{
    ios :: sync_with_stdio(false);
    int N, M;
    string line;
    cin>>N;
    getline(cin, line);
    docs.resize(N);
    
    for(int i = 0; i < N; i++) {
        Doc& d = docs[i];
        while(true) {
            getline(cin, line);
            if(line == "**********") break;
            Lines.push_back(line);
            d.AddLine(line, Lines.size()-1);
        }
    }
    
    cin>>M;
    getline(cin, line);
    vector<string> qWs;
    for(int i = 0; i < M; i++) {
        getline(cin, line);
        parseQuery(line, qWs);
        doQuery(qWs);
    }
    system("pause");
    return 0;
}