#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<int> Q;
    vector<int> V;
    int n;
    while ((cin >> n) && n)
    {
        
        for (int i = 0; i < n; i++) 
        {
            V.push_back(i + 1); 
            Q.push(i + 1);
        }
        cout << "Discarded cards:";
        while (Q.size() != 1)
        {
            cout << " " << Q.front() << ",";
            Q.pop();
            Q.push(Q.front());
            Q.pop();
        }
        cout << "\nRemaining card: " << Q.front() << endl;
        Q.pop();
    }
    system("pause");
    return 0;
}