//모범답안
#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
void solve(vector<int> &a, int index, int cnt) {
if (cnt == 6) { // 완료조건 : 6개를 선택했을때
for (int num : lotto) {
printf("%d ",num);
}
printf("\n");
return;
}
int n = a.size();
if (n == index) return; // 불가능조건 : index초과
lotto.push_back(a[index]); // 선택된 로또번호를 lotto배열에 입력
solve(a,index+1,cnt+1); // 선택한 경우
lotto.pop_back(); // 선택됐던 로또번호를 lotto배열에서 제거
solve(a,index+1,cnt); // 선택하지 않은 경우
}
int main() {
while (true) {
int n;
cin >> n; // 로또숫자 개수 입력
if (n == 0) break;
vector<int> a(n); // 로또숫자 개수만큼의 배열
for (int i=0; i<n; i++) {
cin >> a[i];
}
solve(a, 0, 0); // 재귀함수 호출
cout << '\n';
}
return 0;
}
