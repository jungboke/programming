#include <iostream>
using namespace std;
int a[20];
int n, m;
int ans = 0;
void go(int i, int sum) {
if (i == n) { // 완료조건 : 마지막 index
if (sum == m) {
ans += 1;
}
return;
}
go(i+1, sum+a[i]); // 해당index의 값 선택했을때
go(i+1, sum); // 해당index의 값 선택하지 않았을때
}
int main() {
cin >> n >> m;
for (int i=0; i<n; i++) {
cin >> a[i];
}
go(0, 0); // 재귀함수
if (m == 0) ans -= 1; // 부분수열의 합이 0이될때만 0개의 부분수열이 나올수 있음
cout << ans << '\n';
return 0;
}
