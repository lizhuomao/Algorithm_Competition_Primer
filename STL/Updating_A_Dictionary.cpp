#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while (T--)
    {
        getchar();
        map<string, string> input, input_;
        string line, A, B;
        getline(cin, line);
        for (int i = 0; i < line.size(); i++) 
            if (line[i] == '{' || line[i] == '}' || line[i] == ':' || line[i] == ',') line[i] = ' ';
        //cout << line << endl;
        stringstream ss(line);
        while (ss >> A >> B)
        {
            input[A] = B;
            //cout << A << "  " << B << endl;
        }
        line.clear();
        getline(cin, line);
        for (int i = 0; i < line.size(); i++)
            if (line[i] == '{' || line[i] == '}' || line[i] == ':' || line[i] == ',') line[i] = ' ';
        //cout << line << endl;
        stringstream sss(line);
        vector<string> Sj, Sx;
        int flag = 0;
        while (sss >> A >> B)
        {
            input_[A] = B;
            //cout << A << "  " << B << endl;
            if (!input.count(A))
            {
                flag = 1;
                Sj.push_back(A);
            }
            if (input.count(A))
            {
                string& C = input[A];
                if (C != B)
                {
                   // cout << input.count(A) << " "  << A << " " << endl;
                    flag = 1;
                    Sx.push_back(A);
                }
            }
        }
        if (!Sj.empty())
        {
            int flag_ = 0;
            cout << "+";
            for (vector<string> :: iterator it = Sj.begin(); it != Sj.end(); it++)
            {
                cout << (flag_ == 0 ? "" : ",") << *it;
                flag_ = 1;
            }
            cout << endl;
        }
        if (!Sj.empty())
        {
            int flag_ = 0;
            cout << "*";
            for (vector<string> :: iterator it = Sx.begin(); it != Sx.end(); it++)
            {
                cout << (flag_ == 0 ? "" : ",")<< *it;
                flag_ = 1;
            }
            cout << endl;
        }
        //cout << input.size() << " " << input_.size();
        if (input != input_)
        {
            cout << "-";
            int flag_ = 0;
            for(map<string, string> :: iterator it = input.begin(); it != input.end(); it++) 
            if (input.count((*it).first) && !input_.count((*it).first))
            {
                cout << (flag_ == 0 ? "" : ",") << (*it).first;
                flag_ = 1;
            }
            cout << endl;
        }
        else if (input == input_)
        {
            cout << "No changes" << endl;
        }
    }
    system("pause");
    return 0;
}
