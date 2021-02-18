//모범답안
#include <iostream>
using namespace std;
bool c[20*100000+10]; // 부분수열의 총합값 체크를 위한 bool형 배열
int a[20];
int n;
void go(int i, int sum) {
if (i == n) { // 완료조건: 마지막 index
c[sum] = true; // 부분수열의 총합값 체크
return;
}
go(i+1, sum+a[i]); // 해당index의 수를 선택했을때
go(i+1, sum); // 해당index의 수를 선택하지 않았을때
}
int main() {
cin >> n;
for (int i=0; i<n; i++) {
cin >> a[i]; // 수열 입력
}
go(0, 0); // 재귀함수 실행
for (int i=1;; i++) {
if (c[i] == false) {
cout << i << '\n';
break;
}
}
return 0;
}
