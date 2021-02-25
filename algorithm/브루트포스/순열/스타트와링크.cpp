//모범답안
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
int n;
cin >> n;
vector<vector<int>> a(n, vector<int>(n)); // 2차원 배열을 vector를 써서 나타내는 방법
for (int i=0; i<n; i++) {
for (int j=0; j<n; j++) {
cin >> a[i][j];
}
}
vector<int> b(n); // 1팀 0 2팀 1 로 판단하여 그 순열을 집어넣기 위한 배열
for (int i=0; i<n/2; i++) { // 11110000...
b[i] = 1;
}
sort(b.begin(), b.end()); // permutation을 돌리기위한 초기sorting
int ans = 2147483647;
do { // 팀을 나타내는 0,1 배열을 순열화
vector<int> first, second;
for (int i=0; i<n; i++) {
if (b[i] == 0) {
first.push_back(i);
} else {
second.push_back(i);
}
}
int one = 0;
int two = 0;
for (int i=0; i<n/2; i++) { // 1팀 2팀의 시너지 총합계산
for (int j=0; j<n/2; j++) {
if (i == j) continue;
one += a[first[i]][first[j]];
two += a[second[i]][second[j]];
}
}
int diff = one-two;
if (diff < 0) diff = -diff;
if (ans > diff) ans = diff; // 최소값을 구하기 위한 알고리즘인데, 초기 ans 값을 매우 큰 값으로 설정하고 다음 값들과 비교
} while(next_permutation(b.begin(), b.end()));
cout << ans << '\n';
return 0;
}
