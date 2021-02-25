//모범답안
#include <iostream>
#include <queue>
#include <cstdio> // printf, scanf등을 c++에서 사용할때 추가해줘야함
#include <tuple> // pair보다 한단계높은 tuple을 사용할때 추가해줘야함
using namespace std;
int a[1000][1000]; // 칸의 정보를 나타내기 위한 배열
int d[1000][1000][2]; // 벽을 부쉈는가에 대한 여부에 따라 동일한 정점의 이동가능방향이 달라지기 때문에 벽을 부순 여부도 추가해줘야함 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
int n, m;
scanf("%d %d",&n,&m);
for (int i=0; i<n; i++) {
for (int j=0; j<m; j++) {
scanf("%1d",&a[i][j]);
}
}
queue<tuple<int,int,int>> q; //bfs
d[0][0][0] = 1; //bfs
q.push(make_tuple(0,0,0)); //bfs
while (!q.empty()) { //bfs
int x, y, z;
tie(x,y,z) = q.front(); q.pop(); //bfs
for (int k=0; k<4; k++) {
int nx = x+dx[k];
int ny = y+dy[k];
if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
if (a[nx][ny] == 0 && d[nx][ny][z] == 0) { // 이동하려는 칸이 빈칸일 경우
d[nx][ny][z] = d[x][y][z] + 1;
q.push(make_tuple(nx,ny,z));
}
if (z == 0 && a[nx][ny] == 1 && d[nx][ny][z+1] == 0) { // 이동하려는 칸이 벽일 경우
d[nx][ny][z+1] = d[x][y][z] + 1;
q.push(make_tuple(nx,ny,z+1));
}
}
}
if (d[n-1][m-1][0] != 0 && d[n-1][m-1][1] != 0) { // 구하려는 점이 벽을 깨거나 안깨도 도달가능한 경우 둘중 최솟값을 출력
cout << min(d[n-1][m-1][0], d[n-1][m-1][1]);
} else if (d[n-1][m-1][0] != 0) {
cout << d[n-1][m-1][0];
} else if (d[n-1][m-1][1] != 0) {
cout << d[n-1][m-1][1];
} else {
cout << -1;
}
cout << '\n';
return 0;
}
