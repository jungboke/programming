//모범답안
#include <iostream>
#include <queue>
using namespace std;
int n, m;
int a[10][10];
int b[10][10];
int dx[] = {0,0,1,-1}; // 상하좌우 좌표이동을 위한 배열
int dy[] = {1,-1,0,0};
int bfs() {
queue<pair<int,int>> q; //bfs 
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
b[i][j] = a[i][j]; // 바이러스전파되는 모습을 나타내기위해 기존배열에서 똑같은 배열을 복사해서 사용
if (b[i][j] == 2) {
q.push(make_pair(i,j)); // 바이러스시 queue에 투입 //bfs
}
}
}
while (!q.empty()) { //bfs
int x = q.front().first; //bfs
int y = q.front().second; //bfs
q.pop(); //bfs
for (int k=0; k<4; k++) {
int nx = x+dx[k];
int ny = y+dy[k];
if (0 <= nx && nx < n && 0 <= ny && ny < m) {
if (b[nx][ny] == 0) {
b[nx][ny] = 2; // 전파시 빈칸을 바이러스칸으로 변경
q.push(make_pair(nx,ny)); //bfs
}
}
}
}
int cnt = 0;
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
if (b[i][j] == 0) { // 바이러스에 전파되지 않은 칸을 count
cnt += 1;
}
}
}
return cnt;
}
int main() {
cin >> n >> m;
for (int i=0; i<n; i++) { // n개중 k개를 고르는 nCk식의 상황을 풀수있는 방법중 하나인 중첩for문, k가 변수가 아닌 상수일시 사용가능
for (int j=0; j<m; j++) {
cin >> a[i][j];
}
}
int ans = 0;
for (int x1=0; x1<n; x1++) {
for (int y1=0; y1<m; y1++) {
if (a[x1][y1] != 0) continue; // 벽이나 바이러스가 있는칸에 추가벽 생성불가
for (int x2=0; x2<n; x2++) {
for (int y2=0; y2<m; y2++) {
if (a[x2][y2] != 0) continue;
for (int x3=0; x3<n; x3++) {
for (int y3=0; y3<m; y3++) {
if (a[x3][y3] != 0) continue;
if (x1 == x2 && y1 == y2) continue; // 바이러스 설정시 같은 칸에 여러개 있으면 안됨
if (x1 == x3 && y1 == y3) continue; // 바이러스 설정시 같은 칸에 여러개 있으면 안됨
if (x2 == x3 && y2 == y3) continue; // 바이러스 설정시 같은 칸에 여러개 있으면 안됨
a[x1][y1] = 1;
a[x2][y2] = 1;
a[x3][y3] = 1;
int cur = bfs();
if (ans < cur) ans = cur;
a[x1][y1] = 0;
a[x2][y2] = 0;
a[x3][y3] = 0;
}
}
}
}
}
}
cout << ans << '\n';
return 0;
}
