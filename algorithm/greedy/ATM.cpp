//모범답안
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
int n;
cin >> n;
vector<int> a(n);
for (int i=0; i<n; i++) cin >> a[i];
sort(a.begin(),a.end());
int sum = 0;
int ans = 0;
for (int i=0; i<n; i++) { // 누적합 구하는 for문
sum += a[i];
ans += sum;
}
cout << ans << '\n';
return 0;
}