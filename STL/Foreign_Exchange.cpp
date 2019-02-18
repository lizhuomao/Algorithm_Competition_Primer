#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    map<int , int> M1, M2;
    while ((cin >> n) && n)
    {
        M1.clear();
        M2.clear();
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            M1[a] = b;
            M2[b] = a;
        }
        int flag = 0;
        for (map<int, int> :: iterator it = M1.begin(); it != M1.end(); it++)
        {
        //    cout << M2[(*it).first] << " " << (*it).second << endl;
            if (M2[(*it).first] != (*it).second) { flag = 1; break;}
        }
        cout << (flag == 1 ? "NO" : "YES") << endl;
    }
    system("pause");
    return 0;
}
