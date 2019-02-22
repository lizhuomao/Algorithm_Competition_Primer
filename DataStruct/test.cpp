#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

struct Node {
  int r, c, dir; // վ��(r,c)���泯����dir(0~3�ֱ��ʾN, E, S, W)
  Node(int r=0, int c=0, int dir=0):r(r),c(c),dir(dir) {}
};

const int maxn = 10;
const char* dirs = "NESW"; // ˳ʱ����ת
const char* turns = "FLR";

int has_edge[maxn][maxn][4][3];//����ÿһ������ľ���ת��ʽ
int d[maxn][maxn][4];//�����ۼ���㵽�յ�ľ���
Node p[maxn][maxn][4];//p[r][c][dir]��ʾ��(r,c,dir)��BFS���еĸ��ڵ�
int r0, c0, dir, r1, c1, r2, c2;

int dir_id(char c) { return strchr(dirs, c) - dirs; }//����c��dirs��λ��
int turn_id(char c) { return strchr(turns, c) - turns; }

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

Node walk(const Node& u, int turn) {
  int dir = u.dir;
  if(turn == 1) dir = (dir + 3) % 4; // ��ʱ�룬��ʾ��ת
  if(turn == 2) dir = (dir + 1) % 4; // ˳ʱ�룬��ʾ��ת
  return Node(u.r + dr[dir], u.c + dc[dir], dir);
}

//�ж������Ƿ����
bool inside(int r, int c) {
  return r >= 1 && r <= 9 && c >= 1 && c <= 9;
}

//��ʼ����㣬�յ��ÿһ�������ת��
bool read_case() {
  char s[99], s2[99];
  //s��ָ��ǰ�����̣�r0��ʾ��ʼ�У�c0��ʾ��ʼ�У�s2��ʼ����r2��ʾĿ���У�c2��ʾĿ����
  if(scanf("%d%d%s%d%d", &r0, &c0, s2, &r2, &c2) != 5) return false;

  dir = dir_id(s2[0]);//�������ַ���dirs�е�λ��
  r1 = r0 + dr[dir];//��һ��֮���������
  c1 = c0 + dc[dir];//�ڶ���֮���������

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
  // ��Ŀ��������׷�ݵ���ʼ���
  vector<Node> nodes;
  for(;;) {
    nodes.push_back(u);
    if(d[u.r][u.c][u.dir] == 0) break;//˵���ҵ����յ�
    u = p[u.r][u.c][u.dir];
  }
  nodes.push_back(Node(r0, c0, dir));

  // ��ӡ�⣬ÿ��10��
  int cnt = 0;
  for(int i = nodes.size()-1; i >= 0; i--) {
    printf(" (%d,%d) ", nodes[i].r, nodes[i].c);
    if(++cnt == 10){
        printf("\n");
    }
  }
}

//ʹ��BFS���
void solve() {
  queue<Node> q;
  memset(d, -1, sizeof(d));
  //��һ��֮�󣬴��ڣ�2,1��N����״̬
  Node u(r1, c1, dir);//����һ��֮�������
  d[u.r][u.c][u.dir] = 0;
  q.push(u);
  while(!q.empty()) {
    Node u = q.front(); q.pop();
    if(u.r == r2 && u.c == c2) { print_ans(u); return; }
    //�жϵ�ǰ����㣬�ڵ�ǰת������������ĸ��ǿ�����ʹ�ģ�
    for(int i = 0; i < 3; i++) {
      Node v = walk(u, i);
      //v��u��������һ��֮������꣬�ߵ��յ�û�г�ʼ����has_edgeֵΪ0��������ѭ��
      if(has_edge[u.r][u.c][u.dir][i] && inside(v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
        d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;//�ۼ�1�����ó���㵽�յ�ľ���
        p[v.r][v.c][v.dir] = u;//��ʾv�ĸ��ڵ���u
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