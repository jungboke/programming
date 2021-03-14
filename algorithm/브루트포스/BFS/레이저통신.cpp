//모범답안
#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int main() {
int m, n;
cin >> m >> n;
vector<string> a(n);
int sx,sy,ex,ey; // 시작점과 끝점
sx=sy=ex=ey=-1;
for (int i=0; i<n; i++) {
cin >> a[i];
for (int j=0; j<m; j++) {
if (a[i][j] == 'C') {
if (sx == -1) {
sx = i;
sy = j;
} else {
ex = i;
ey = j;
}
}
}
}
vector<vector<int>> d(n, vector<int>(m, -1)); // ** n행m열의 배열을 설정하고 -1로 초기화
queue<pair<int,int>> q;
d[sx][sy] = 0; // 해당칸까지의 직선의 개수
q.push(make_pair(sx,sy));
while (!q.empty()) {
int x, y;
tie(x,y) = q.front(); q.pop();
for (int k=0; k<4; k++) {
int nx = x+dx[k];
int ny = y+dy[k];
while (0 <= nx && nx < n && 0 <= ny && ny < m) { // 십자형으로 퍼져나가는게 아닌 일자형으로 벽까지 퍼져나감
if (a[nx][ny] == '*') break;
if (d[nx][ny] == -1) {
d[nx][ny] = d[x][y] + 1;
q.push(make_pair(nx,ny));
}
nx += dx[k];
ny += dy[k];
}
}
}
cout << d[ex][ey]-1 << '\n'; // 거울의 수는 직선의 수 -1 임
return 0;
}
