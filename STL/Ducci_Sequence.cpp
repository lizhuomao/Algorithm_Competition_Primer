#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> A;
    while (n--)
    {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    int cnt = 0;
    while (cnt < 1000)
    {
        int temp = A[0];
        for (int i = 0; i < A.size() - 1; i++)
        {
            A[i] = abs(A[i] - A[i + 1]);
        }
        A[A.size() - 1] = abs(A[A.size() - 1] - temp);
        int flag = 0;
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
            if (A[i] != 0) flag = 1;
        }
        cout << endl;
        if (!flag)
        {
            printf("YES\n");
            break;
        }
        cnt++;
    }
    if (cnt >= 1000)
    {
        printf("NO\n");
    }
    system("pause");
    return 0;
}
