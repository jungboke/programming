//모범답안
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
const int LIMIT = 10;
vector<int> gen(int k) {
vector<int> a(LIMIT);
for (int i=0; i<LIMIT; i++) { // 20자리 이진법수를 10자리 삼진법수로 바꾸기 위한 
a[i] = (k&3);
k >>= 2;
}
return a;
}
pair<bool,bool> simulate(vector<string> &a, int k, int &x, int &y) {
if (a[x][y] == '.') return make_pair(false, false); // 구슬이 구멍에 빠진상태면 함수실행 
int n = a.size(); // 행의 단위
int m = a[0].size(); // 열의 단위
bool moved = false; // 움직임 확인하기위한 bool형 변수
while (true) {
int nx = x+dx[k];
int ny = y+dy[k];
if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
return make_pair(moved, false);
}
if (a[nx][ny] == '#') { // 벽일시 움직이지 않음
return make_pair(moved, false);
} else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') { // 이동하려는 곳에 구슬있으면 움직이지 않음
return make_pair(moved, false);
} else if (a[nx][ny] == '.') { // 이동하려는 곳이 비어있으면 구슬좌표랑 .좌표 바꾸기
swap(a[nx][ny], a[x][y]); // vector header의 swap함수
x = nx;
y = ny;
moved = true;
} else if (a[nx][ny] == 'O') { // 이동하려고 곳이 구멍이면 구슬칸을 .로 대체
a[x][y] = '.';
moved = true;
return make_pair(moved, true);
}
}
return make_pair(false, false);
}
int check(vector<string> a, vector<int> &dir) {
int n = a.size(); // 행의 단위
int m = a[0].size(); // 열의 단위
int hx,hy,rx,ry,bx,by; // hx,hy : 구멍좌표 rx,ry : 빨간구슬좌표 bx,by : 파란구슬좌표
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
if (a[i][j] == 'O') {
hx = i; hy = j;
} else if (a[i][j] == 'R') {
rx = i; ry = j;
} else if (a[i][j] == 'B') {
bx = i; by = j;
}
}
}
int cnt = 0;
for (int k : dir) {
cnt += 1;
bool hole1=false, hole2=false; // 빨간구슬 들어가면 hole1 true, 파란구슬 들어가면 hole2 true 
while (true) {
auto p1 = simulate(a, k, rx, ry); // first : 이동했는가에 대한 bool형, second : 구멍에 들어갔는가에 대한 bool형
auto p2 = simulate(a, k, bx, by); // 빨간구슬이 움직이고 난뒤 변화한 칸의모습을 
if (p1.first == false && p2.first == false) { // 두 구슬다 이동하지 않을시 무한루프 break why)한쪽끝으로 다이동해야 두 구슬이 이동하지 않음
break;
}
if (p1.second) hole1 = true;
if (p2.second) hole2 = true;
}
if (hole2) return -1; // 파란구슬빠지면 -1 return
if (hole1) return cnt; // 빨간구슬빠지면 cnt에 +1
}
return -1; // 둘다안빠지면 -1
}
bool valid(vector<int> &dir) {
int l = dir.size();
for (int i=0; i+1<l; i++) {
if (dir[i] == 0 && dir[i+1] == 1) return false; // 연속반대방향이면 불가
if (dir[i] == 1 && dir[i+1] == 0) return false;
if (dir[i] == 2 && dir[i+1] == 3) return false;
if (dir[i] == 3 && dir[i+1] == 2) return false;
if (dir[i] == dir[i+1]) return false; // 연속동일방향이면 불가
}
return true;
}
int main() {
int n, m;
cin >> n >> m;
vector<string> a(n); // 판의 상태를 나타내기위한 2차원 배열
for (int i=0; i<n; i++) {
cin >> a[i];
}
int ans = -1;
for (int k=0; k<(1<<(LIMIT*2)); k++) { // 20자리의 2진법수를 놔야 3진법의 10자리수를 만들수 있음
vector<int> dir = gen(k);  // gen()함수를 통한 2진법수를 10자리의 3진법으로 변환
if (!valid(dir)) continue; // 같은방향 연속이동, 반대방향 연속이동을 제거하기 위한 valid()함수 체크
int cur = check(a, dir); 
if (cur == -1) continue;
if (ans == -1 || ans > cur) ans = cur;
}
cout << ans << '\n';
return 0;
}
