//모범답안
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int calc(vector<int> &a, vector<int> &b) { 숫자배열과 연산자배열을 통해 값을 계산
int n = a.size(); 
int ans = a[0];
for (int i=1; i<n; i++) {
if (b[i-1] == 0) {
ans = ans + a[i];
} else if (b[i-1] == 1) {
ans = ans - a[i];
} else if (b[i-1] == 2) {
ans = ans * a[i];
} else {
ans = ans / a[i];
}
}
return ans;
}
int main() {
int n;
cin >> n;
vector<int> a(n); // 숫자를 입력하기 위한 배열
for (int i=0; i<n; i++) {
cin >> a[i];
}
vector<int> b; // 연산자를 숫자로 변환하고 담아두기 위한 배열
for (int i=0; i<4; i++) {
int cnt;
cin >> cnt;
for (int k=0; k<cnt; k++) {
b.push_back(i); 
}
}
sort(b.begin(),b.end());
vector<int> result; // 결과값들을 담아두기 위한 배열
do {
int temp = calc(a, b);
result.push_back(temp);
} while (next_permutation(b.begin(), b.end()));
auto ans = minmax_element(result.begin(), result.end()); // result내부의 최대최소값 pair을 맞추기위해 auto사용
cout << *ans.second << '\n'; // *ans.first, *ans.second 로 최대값, 최소값 호출
cout << *ans.first << '\n';
return 0;
}
