//모범답안
#include <iostream>
using namespace std;
bool a[15][15];
int n;
bool check_col[15]; // 해당 열에 queen 존재하면 true
bool check_dig[40]; // x+y을 index로 해당 대각선의 index에 queen 존재하면 true
bool check_dig2[40]; // x-y+n값의 합을 index로 해당 대각선의 index에 queen 존재하면 true
bool check(int row, int col) { // 세로 왼위대각선 우위대각선에 겹치는 queen 있는지 확인하기 위한 함수
// |
if (check_col[col]) {  
return false;
}
// 왼쪽 위 대각선
if (check_dig[row+col]) {
return false;
}
// /
if (check_dig2[row-col+n]) {
return false;
}
return true; // 방해되는 queen없으면 true return
}
int calc(int row) {
if (row == n) { // 완료조건: 마지막 열 index 초과
// ans += 1;
return 1; // 완료시 cnt에 1씩 리턴해서 더함
}
int cnt = 0; // 초기 cnt값 
for (int col=0; col<n; col++) {
if (check(row, col)) { // 해당 칸에 queen 놓아도되는지 검사
check_dig[row+col] = true; 
check_dig2[row-col+n] = true;
check_col[col] = true;
a[row][col] = true; 
cnt += calc(row+1);
check_dig[row+col] = false; // 마지막에 둔 queen 제거
check_dig2[row-col+n] = false;
check_col[col] = false;
a[row][col] = false;
}
}
return cnt;
}
int main() {
cin >> n; 
cout << calc(0) << '\n'; // 첫번째 행부터 재귀함수 실행
return 0;
}
