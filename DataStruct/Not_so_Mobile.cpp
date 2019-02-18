#include <iostream>
using namespace std;

bool solve(int& M)
{
    int M1, D1, M2, D2;
    cin >> M1 >> D1 >> M2 >> D2;
    bool b1 = true, b2 = true;
    if (!M1) b1 = solve(M1);
    if (!M2) b2 = solve(M2);
    M = M1 + M2;
    return (b1 && b2 && (M1 * D1 == M2 * D2));
}

int main(int argc, char const *argv[])
{
    int T, M;
    cin >> T;
    while (T--)
    {
        if (solve(M)) { cout << "Yes\n";}
        else { cout << "No\n";}
    }
    system("pause");
    return 0;
}
