#include <cassert>
#include <cstdlib>
#include <functional>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)
using namespace std;

struct Point {
  int x, y;
  Point(int x=0, int y=0):x(x),y(y) {}
};
typedef Point Vector;

Vector operator+ (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator- (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator* (const Vector& A, int p) { return Vector(A.x*p, A.y*p); }
Vector operator/ (const Vector& A, int p) { return Vector(A.x/p, A.y/p); }
bool operator== (const Point& a, const Point &b) { return a.x == b.x && a.y == b.y; }
bool operator< (const Point& p1, const Point& p2) { return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y); }
// istream& operator>>(istream& is, Point& p) { return is>>p.x>>p.y; }
// ostream& operator<<(ostream& os, const Point& p) { return os<<"["<<p.x<<","<<p.y<<"]"; }
// x in [left, right]
bool inRange(int x, int left, int right) {
    if(left > right) return inRange(x, right, left);
    return left <= x && x <= right;
}
Point blackG, redG; // ��˧
char board[16][16];
vector<Point> 
    DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}}, // 4������
    HDIRS = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}}, // ������
    redPieces;

bool inBPalace(const Point& bPos) { return inRange(bPos.x, 1, 3) && inRange(bPos.y, 4, 6); }

// p1�ܲ���ֱ�ӷɵ�p2���м���sz������
bool canFly(const Point& p1, const Point& p2, int sz = 0) {
    bool v = (p1.x == p2.x), h = (p1.y == p2.y);
    assert(v || h); assert(!(v&&h));
    int lx = min(p1.x, p2.x), ux = max(p1.x, p2.x),
        ly = min(p1.y, p2.y), uy = max(p1.y, p2.y),
        cnt = 0;
    if(v) {
        _for(y, ly+1, uy)
            if(board[p1.x][y] && ++cnt > sz) return false;
        return cnt == sz;
    }
    
    _for(x, lx+1, ux)
        if(board[x][p1.y] && ++cnt > sz) return false;
    return cnt == sz;
}

// r����ĺ����ӻ᲻��Ե�b����ĺ�����
bool checkmate(const Point& r, const Point& b) {
    // cout<<"try checkmate "<<r<<" "<<b<<endl;
    bool ans = true;
    switch(board[r.x][r.y]) {
        case 'G': // general ��˧����
            return r.y == b.y && canFly(r, b);
        case 'R': // chariot ���Խ�
            return (r.x == b.x || r.y == b.y) && canFly(r, b);
        case 'H': // horse ������������������
            for(const auto& HD : HDIRS) {
                Point hPos = r + HD, legPos = r + HD/2;
                if(hPos == b && board[legPos.x][legPos.y] == 0) return true;
            }
            return false;
        case 'C': // �ڴ�
            return (r.x == b.x || r.y == b.y) && canFly(r, b, 1);
        default:
            assert(false);
            break;
    }
}

bool canWin() {
    assert(inBPalace(blackG));
    if(blackG.y == redG.y && canFly(blackG, redG))
        return false; 

    for(const auto& D : DIRS) { // ���Ը��ַ��򣬿����ܲ��ܲ�������
        Point bp = blackG + D;
        if(!inBPalace(bp)) continue; // ����
        
        char back = board[bp.x][bp.y];
        board[bp.x][bp.y] = 0; // ���ӿ��ܱ��Ե���
        
        bool live = true;
        for(const auto& r : redPieces) {
            if(board[r.x][r.y] && checkmate(r, bp)) {
                live = false;             
                break;
            }
        }
        
        board[bp.x][bp.y] = back;
        if(live) return false;
    }
    return true;
}

int main(){    
    int N;    
    while(scanf("%d%d%d", &N, &(blackG.x), &(blackG.y)) == 3 && N){
        redPieces.clear();
        memset(board, 0, sizeof(board));
        _for(i, 0, N){
            char type;
            Point p;
            getchar();
            scanf("%c%d%d", &type, &(p.x), &(p.y));
            redPieces.push_back(p);
            board[p.x][p.y] = type;
            if(type == 'G') redG = p;
        }

        puts(canWin()?"YES":"NO");        
    }
    system("pause");
    return 0;
}
