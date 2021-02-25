//모범답안
#include <iostream>
using namespace std;
int n, m;
string a[20];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int go(int step, int x1, int y1, int x2, int y2) {
if (step == 11) return -1; // 불가능조건: 시도회수가 10번을 넘어갔을때
bool fall1=false, fall2=false;
if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true; // 1번동전이 떨어졌을때
if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true; // 2번동전이 떨어졌을때
if (fall1 && fall2) return -1; // 불가능조건: 두동전모두 동시에 떨어졌을때
if (fall1 || fall2) return step; // 완료조건: 두동전중 하나만 떨어졌을때
int ans = -1;
for (int k=0; k<4; k++) { // 동전이 한번 이동할때의 좌표이동
int nx1 = x1+dx[k];
int ny1 = y1+dy[k];
int nx2 = x2+dx[k];
int ny2 = y2+dy[k];
if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#') { // 1번동전이 이동불가할때
nx1 = x1;
ny1 = y1;
}
if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') { // 2번동전이 이동불가할때
nx2 = x2;
ny2 = y2;
}
int temp = go(step+1, nx1, ny1, nx2, ny2); // temp가 최소이동수 혹은 -1를 받음
if (temp == -1) continue; // -1을 받았을때 상하좌우 다른 좌표이동으로 넘어감
if (ans == -1 || ans > temp) { // 최소값을 구하는 알고리즘중 하나로 초기 ans를 -1로 초기화하는 방식
ans = temp; // 완료조건시 최소이동값을 받고 상하좌우 다른 좌표이동으로 넘어감
}
}
return ans; // 상하좌우 다이동했을시 가지고있는 최소이동값을 전칸으로 넘겨줌
}
int main() {
cin >> n >> m;
int x1,y1,x2,y2;
x1=y1=x2=y2=-1;
for (int i=0; i<n; i++) {
cin >> a[i];
for (int j=0; j<m; j++) {
if (a[i][j] == 'o') {
if (x1 == -1) {
x1 = i;
y1 = j;
} else {
x2 = i;
y2 = j;
}
a[i][j] = '.';
}
}
}
cout << go(0,x1,y1,x2,y2) << '\n';
return 0;
}
