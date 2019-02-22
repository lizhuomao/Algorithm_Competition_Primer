#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

const int MAX_N = 200 + 10, dir[2][4] = {-1, 1, 0, 0, 0, 0, -1, 1};
const char bin[17][5] = 
{
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
}, ctr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}, *s = "WAKJSD";
int H, W, pic[MAX_N][MAX_N], color[MAX_N][MAX_N], kase = 0;
char line[MAX_N];
vector<set<int>> neighbor;

void decode(char c, int row, int col)
{
    for (int i = 0; i < 16; i++)
    {
        if (ctr[i] == c)
        {
            for (int j = 0; j < 4; j++)
            {
                pic[row][col + j] = bin[i][j] - '0';
            }
        }
    }
    return;
}
void dfs(int row, int col, int num)
{

    color[row][col] = num;
    for (int i = 0; i < 4; i++)
    {
        int drow = row + dir[0][i], dcol = col + dir[1][i];
        if (drow >= 0 && drow < H && dcol >= 0 && dcol < W && !color[drow][dcol] && pic[drow][dcol] == pic[row][col])
        {
            dfs(drow, dcol, num);
        }
    }
    return;
}
void check_neighbor(int row, int col)
{
    for (int i = 0; i < 4; i++)
    {
        int drow = row + dir[0][i], dcol = col + dir[1][i];
        if (drow >= 0 && drow < H && dcol >= 0 && dcol < W && pic[drow][dcol] == 0 && color[drow][dcol] != 1)
        {
            neighbor[color[row][col]].insert(color[drow][dcol]);
        }
    }
    return;
}
char recognize(int num)
{
    int c = neighbor[num].size();
    return s[c];
}

int main(void)
{
    while (scanf("%d %d", &H, &W) == 2 && H && W)
    {
        memset(pic, 0, sizeof(pic));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < H; i++)
        {
            scanf("%s", line);
            for (int j = 0; j < W; j++)
            {
                decode(line[j], i + 1, j * 4 + 1);
            }
        }
        H += 5;
        W = W * 4 + 5;
        int cnt = 0;
        vector<int> vec;
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                if (!color[h][w])
                {
                    dfs(h, w, ++cnt);
                    if (pic[h][w] == 1) vec.push_back(cnt);
                }
            }
        }
        neighbor.clear();
        neighbor.resize(cnt + 5);
        for (int h = 0; h < H; h++)
        {
            for (int w = 0; w < W; w++)
            {
                if (pic[h][w] == 1)
                {
                    check_neighbor(h, w);
                }
            }
        }
        vector<char> ans;
        for (int i = 0; i < vec.size(); i++)
        {
            ans.push_back(recognize(vec[i]));
        }
        sort(ans.begin(), ans.end());
        cout << "Case:" << ++kase << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    system("pause");
    return 0;
}