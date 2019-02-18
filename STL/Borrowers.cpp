#include <iostream>
#include <assert.h>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
struct node
{
    string title, author;
    node(string& a, string& b) : title(a), author(b){};
    bool operator < (const node& p) { return author < p.author || (author == p.author && title < p.title);}
};

vector<node> books;
map<string, int> bookIndice;
struct indexComp
{
    bool operator() (const int& lhs, const int& rhs) const{ return books[lhs] < books[rhs];}
};
set<int, indexComp> shelf, lib;
void shelve()
{
    for (set<int> :: iterator it = shelf.begin(); it != shelf.end(); it++)
    {
        int idx = *it;
        set<int> :: iterator pit = lib.insert(idx).first;
        if (pit == lib.begin())
        {
            cout << "Put " << books[idx].title << " first" << endl;
        }
        else 
        {
            pit--;
            cout << "Put " << books[idx].title << " after" << books[*pit].title << endl;
        }
    }
}
void borrow(const string& s)
{
    int idx = bookIndice[s];
    if (lib.count(idx)) lib.erase(idx);
    else
    {
        shelf.erase(idx);
    }
}
void retBook(const string& s)
{
    int idx = bookIndice[s];
    shelf.insert(idx);
}
int main(int argc, char const *argv[])
{
    string buf;
    while (true)
    {
        getline(cin, buf);
        if (buf == "END") break;
        int spos = buf.find(" by ");
        string title = buf.substr(0, spos), author =buf.substr(spos + 4);
        int idx = books.size();
        bookIndice[title] = idx;
        books.push_back(node(title, author));
    }
    for (int i = 0; i < books.size(); i++) lib.insert(i);
    string cmd, title;
    while (true)
    {
        getline(cin, buf);
        if (buf == "END") break;
        cmd = buf.substr(0, 6);
        if (cmd[0] == 'S') shelve();
        else 
        {
            title = buf.substr(cmd.size() + 1, buf.size() - cmd.size() - 1);
            if (cmd[0] == 'B') borrow(title);
            else retBook(title);
        }
    }
    system("pause");
    return 0;
}


