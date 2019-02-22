#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Node {
  int r, c, dir; // 站在(r,c)，面朝方向dir(0~3分别表示N, E, S, W)
  Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
};

const int maxn = 10;
const char* dirs = "NESW"; // 顺时针旋转
const char* turns = "FLR";

int has_edge[maxn][maxn][4][3];//保存每一个坐标的具体转向方式
int d[maxn][maxn][4];//用来累加起点到终点的距离
Node p[maxn][maxn][4];//p[r][c][dir]表示了(r,c,dir)在BFS树中的父节点
int r0, c0, dir, r1, c1, r2, c2;

int dir_id(char c) { return strchr(dirs, c) - dirs; }//返回c在dirs的位置
int turn_id(char c) { return strchr(turns, c) - turns; }

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

Node walk(const Node& u, int turn) {
  int dir = u.dir;
  if(turn == 1) dir = (dir + 3) % 4; // 逆时针，表示左转
  if(turn == 2) dir = (dir + 1) % 4; // 顺时针，表示右转
  return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

//判断坐标是否出界
bool inside(int r, int c) {
  return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

//初始化起点，终点和每一个坐标的转向
bool read_case() {
  char s[99], s2[99];
  //s是指当前的流程，r0表示起始行，c0表示起始列，s2起始方向，r2表示目标行，c2表示目标列
  if(scanf("%d%d%s%d%d", &r0, &c0, s2, &r2, &c2) != 5) return false;

  dir = dir_id(s2[0]);//方向在字符串dirs中的位置
  r1 = r0 + dr[dir];//第一步之后的行坐标
  c1 = c0 + dc[dir];//第二步之后的列坐标

  memset(has_edge, 0, sizeof(has_edge));
  for(;;) {
    int r, c;
    scanf("%d", &r);
    if(r == 0) break;
    scanf("%d", &c);
    while(scanf("%s", s) == 1 && s[0] != '*') {
      for(int i = 1; i < strlen(s); i++)
        has_edge[r][c][dir_id(s[0])][turn_id(s[i])] = 1;
    }
  }
  return true;
}

void print_ans(Node u) {
  // 从目标结点逆序追溯到初始结点
  vector<Node> nodes;
  for(;;) {
    nodes.push_back(u);
    if(d[u.r][u.c][u.dir] == 0) break;//说明找到了终点
    u = p[u.r][u.c][u.dir];
  }
  nodes.push_back(Node(r0, c0, dir));

  // 打印解，每行10个
  int cnt = 0;
  for(int i = nodes.size()-1; i >= 0; i--) {
    printf(" (%d,%d) ", nodes[i].r, nodes[i].c);
    if(++cnt == 10){
        printf("\n");
    }
  }
}

//使用BFS输出
void solve() {
  queue<Node> q;
  memset(d, -1, sizeof(d));
  //第一步之后，处于（2,1，N）的状态
  Node u(r1, c1, dir);//走了一步之后的坐标
  d[u.r][u.c][u.dir] = 0;
  q.push(u);
  while(!q.empty()) {
    Node u = q.front(); q.pop();
    if(u.r == r2 && u.c == c2) { print_ans(u); return; }
    //判断当前坐标点，在当前转向的三个方向哪个是可以行使的？
    for(int i = 0; i < 3; i++) {
      Node v = walk(u, i);
      //v是u坐标行走一步之后的坐标，走到终点没有初始化，has_edge值为0，不进入循环
      if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
        d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;//累加1，最后得出起点到终点的距离
        p[v.r][v.c][v.dir] = u;//表示v的父节点是u
        q.push(v);
      }
    }
  }
  printf("  No Solution Possible\n");
}

int main() {
  while(read_case()) {
    solve();
  }
  return 0;
}