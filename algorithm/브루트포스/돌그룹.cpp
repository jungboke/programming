//모범답안
#include <iostream>
#include <queue>
using namespace std;
bool check[1501][1501]; // x,y,z 각각의 개수를 나타내기위해 3차원을 안써도, z를 sum-x-y로 나타낼수 있으니 2차원배열로 가능함
int sum;
void go(int x, int y) { //dfs(재귀함수)
if (check[x][y]) return; // 방문한 점이면 return 
check[x][y] = true; //dfs
int a[3] = {x, y, sum-x-y};
for (int i=0; i<3; i++) { // x,y,z 중 2개를 구하기 위한(3C2) 중첩for문
for (int j=0; j<3; j++) {
if (a[i] < a[j]) {
int b[3] = {x, y, sum-x-y};
b[i] += a[i];
b[j] -= a[i];
go(b[0], b[1]); // x,y,z의 구별은 중요치 않고 그중 2개의 개수가 중요함
}
}
}
}
int main() {
int x, y, z;
cin >> x >> y >> z;
sum = x + y + z;
if (sum % 3 != 0) { // x,y,z가 모두 같으려면 총합은 3의배수 이어야함
cout << 0 << '\n';
return 0;
}
go(x, y);
if (check[sum/3][sum/3]) {
cout << 1 << '\n';
} else {
cout << 0 << '\n';
}
return 0;
}
