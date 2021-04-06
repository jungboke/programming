//모범답안
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set> // set함수는 insert시 자동정렬이 되고, 중복되는 원소를 처리하지 않음(트리형 구조 컨테이너)
#include <tuple>
using namespace std;
int n, m;
int a[1000][1000]; // 칸의 내용을 저장하기 위한 배열
bool check[1000][1000]; // 방문여부를 나타내기 위한 배열
int group[1000][1000]; // 빈칸들의 그룹을 구별하기 위한 배열
vector<int> group_size;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(int sx, int sy) { //bfs
int g = group_size.size();
queue<pair<int,int>> q; //bfs
q.push(make_pair(sx,sy)); //bfs
check[sx][sy] = true;
group[sx][sy] = g;
int cnt = 1;
while (!q.empty()) { //bfs
int x, y;
tie(x, y) = q.front(); q.pop(); //bfs
for (int k=0; k<4; k++) {
int nx = x+dx[k];
int ny = y+dy[k];
if (0 <= nx && nx < n && 0 <= ny && ny < m) {
if (a[nx][ny] == 0 && check[nx][ny] == false) {
q.push(make_pair(nx,ny));
check[nx][ny] = true;
group[nx][ny] = g;
cnt += 1;
}
}
}
}
group_size.push_back(cnt); // 매우 창의적인 bfs 그룹화 알고리즘 **
}
int main() {
cin >> n >> m;
for (int i=0; i<n; i++) {
string s; // 띄어쓰기없이 칸내용을 입력받으므로 string으로 써야함
cin >> s;
for (int j=0; j<m; j++) {
a[i][j] = s[j] - '0'; // 문자형의 숫자를 int형으로 저장하기 위해 -'0'사용
check[i][j] = false;
group[i][j] = -1;
}
}
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
if (a[i][j] == 0 && check[i][j] == false) {
bfs(i, j); // 뭉쳐있는 빈칸들을 그룹화하기 위한 첫bfs 사용
}
}
}
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
if (a[i][j] == 0) {
cout << 0;
} else { // 벽칸일 경우
set<int> near; // set생성
for (int k=0; k<4; k++) { // 부순 벽칸의 상하좌우가 벽 또는 칸인지 확인
int x = i+dx[k]; 
int y = j+dy[k];
if (0 <= x && x < n && 0 <= y && y < m) {
if (a[x][y] == 0) { // 상하좌우 중 하나가 빈칸일시 해당 빈칸의 그룹들을 모두 더해야함
near.insert(group[x][y]);
}
}
}
int ans = 1; // 자신의 칸까지 더해야함
for (int g : near) {
ans += group_size[g];
}
cout << ans%10;
}
}
cout << '\n';
}
return 0;
}
