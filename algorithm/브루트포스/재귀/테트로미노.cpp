//모범답안
#include <iostream>
using namespace std;
int a[500][500];
bool c[500][500];
int n, m;
int dx[] = {0,0,1,-1}; // 상하좌우 이동하기 위해 더해야하는 x값
int dy[] = {1,-1,0,0}; // 상하좌우 이동하기 위해 더해야하는 y값
int ans = 0;
void go(int x, int y, int sum, int cnt) {
if (cnt == 4) { // 완료조건 : 블록4개 사용
if (ans < sum) ans = sum;
return;
}
if (x < 0 || x >= n || y < 0 || y >= m) return; // 경계를 넘어가는것을 방지하기 위한 if문
if (c[x][y]) return; // 방문했던 점을 재방문하는것을 방지하기 위한 if문
c[x][y] = true;
for (int k=0; k<4; k++) {
go(x+dx[k],y+dy[k],sum+a[x][y],cnt+1);
}
c[x][y] = false; // 재귀함수 마지막에 방문했던 점 해제하고 한칸후퇴
}
int main() {
cin >> n >> m;
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
cin >> a[i][j]; // 칸마다 값 설정
}
}
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
go(i,j,0,0); // 각 칸마다 재귀함수 실행
if (j+2 < m) { // 뫼산 모양의 테트로미노는 재귀함수로 구할수 없으므로 따로 계산
int temp = a[i][j] + a[i][j+1] + a[i][j+2];
if (i-1 >= 0) {
int temp2 = temp + a[i-1][j+1];
if (ans < temp2) ans = temp2;
}
if (i+1 < n) {
int temp2 = temp + a[i+1][j+1];
if (ans < temp2) ans = temp2;
}
}
if (i+2 < n) {
int temp = a[i][j] + a[i+1][j] + a[i+2][j];
if (j+1 < m) {
int temp2 = temp + a[i+1][j+1];
if (ans < temp2) ans = temp2;
}
if (j-1 >= 0) {
int temp2 = temp + a[i+1][j-1];
if (ans < temp2) ans = temp2;
}
}
}
}
cout << ans << '\n';
return 0;
}
