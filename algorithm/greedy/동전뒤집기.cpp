//모범답안
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
char flip(char x) {
if (x == 'H') return 'T';
else return 'H';
}
int main() {
int n;
cin >> n;
vector<string> a(n);
for (int i=0; i<n; i++) {
cin >> a[i];
}
int ans = n*n;
for (int state=0; state<(1<<n); state++) { //비트마스크로 행들의 뒤집힘을 표현
int sum = 0;
for (int j=0; j<n; j++) { // i,j 순서를 뒤집어서 진행방향을 열 기준으로 함
int cnt = 0; // 현재 열의 T의 개수를 카운트
for (int i=0; i<n; i++) {
char cur = a[i][j];
if (state & (1 << i)) { // 비트마스크로 현재 행이 뒤집히나 확인
cur = flip(cur); // 현재 행이 뒤집히는 행이면 현재 단어 뒤집어줌
}
if (cur == 'T') {
cnt += 1;
}
}
sum += min(cnt, n-cnt); // T나 H중 적은 개수가 뒤집거나 안뒤집거나 결정한뒤 H값이 됨
}
if (ans > sum) ans = sum;
}
cout << ans << '\n';
return 0;
}