//모범답안
#include <iostream>
#include <algorithm>
#include <queue>
#define next _next
using namespace std;
int dist[101]; // 시작점부터 각칸까지 거리를 나타내기위한 배열
int next[101]; // 사다리나 뱀칸에 대응하기 위해 각칸을 밟을시 이동해야되는 칸을 의미, 뱀과 사다리가 아닌걸 밟으면 자기자신으로 이동 
int main() {
int n, m;
cin >> n >> m;
for (int i=1; i<=100; i++) {
next[i] = i;
dist[i] = -1; // dist가 -1이면 아직 방문하지 않음을 의미
}
while (n--) {
int x, y;
cin >> x >> y;
next[x] = y;
}
while (m--) {
int x, y;
cin >> x >> y;
next[x] = y;
}
dist[1] = 0; // 1은 시작점이니까 자기까지의 거리 0
queue<int> q; // bfs알고리즘을 위한 queue선언
q.push(1); // queue에 초기값 투입
while (!q.empty()) { //bfs
int x = q.front(); q.pop(); //bfs
for (int i=1; i<=6; i++) {
int y = x+i;
if (y > 100) continue;
y = next[y]; // 뱀과 사다리일경우를 계산
if (dist[y] == -1) {
dist[y] = dist[x] + 1;
q.push(y); // bfs
}
}
}
cout << dist[100] << '\n';
return 0;
}
