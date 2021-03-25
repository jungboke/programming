//모범답안
#include <iostream>
#include <vector>
using namespace std;
int main() {
int n, k;
cin >> n >> k; // 동전이 배수단위로 올라갈때만 greedy알고리즘 적용가능
vector<int> a(n);
for (int i=0; i<n; i++) {
cin >> a[i];
}
int ans = 0;
for (int i=n-1; i>=0; i--) {
ans += k/a[i];
k %= a[i];
}
cout << ans << '\n';
return 0;
}