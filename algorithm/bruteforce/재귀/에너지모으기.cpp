//모범답안
#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> &a) { // 배열자체를 매개변수로 받는 재귀함수 **재귀함수는 반환형이 int형인가 void형인가 잘봐야함
int n = a.size();
if (n == 2) return 0; // 완료조건 & 불가능조건: 마지막에 구슬2개가 남음
int ans = 0;
for (int i=1; i<n-1; i++) {
int energy = a[i-1]*a[i+1];
vector<int> b(a); // 사용된 구슬을 제거하기 위한 임시배열 복사
b.erase(b.begin()+i); // 구슬제거
energy += go(b); // int 반환형 재귀함수의 특징
if (ans < energy) {
ans = energy;
}
}
return ans; // int 반환형 재귀함수의 특징
}
int main() {
int n;
cin >> n;
vector<int> a(n);
for (int i=0; i<n; i++) {
cin >> a[i];
}
cout << go(a) << '\n'; // 재귀함수 실행
return 0;
}
