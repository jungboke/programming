//모범답안
#include <iostream>
using namespace std;
bool c[20*100000+10]; // 합의 최대값까지 값이 존재하는지 check하기위한 배열생성
int a[20];
int n;
int main() {
cin >> n;
for (int i=0; i<n; i++) {
cin >> a[i]; // 배열 입력
}
for (int i=0; i<(1<<n); i++) { // n개숫자를 가지는 배열의 비트마스크를 구하기 위한 i < (1<<n) 입력
int sum = 0;
for (int j=0; j<n; j++) {
if (i&(1<<j)) { // 한개의 비트마스크내 1값들에 해당하는 배열의 숫자값을 더하기 위한 i&(1<<j) 입력
sum += a[j];
}
}
c[sum] = true;
}
for (int i=1;; i++) {
if (c[i] == false) { // 존재하지 않는 최소의 자연수값을 구하기 위한 for문
cout << i << '\n';
break;
}
}
return 0;
}
