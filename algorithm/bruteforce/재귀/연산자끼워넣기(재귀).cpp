//모범답안
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> calc(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div) { // pair<int,int> 반환형
int n = a.size();
if (index == n) { // 완료조건: 마지막index
return make_pair(cur, cur); // 최솟값 최대값을 묶어서 계산하기 위해 설정
}
vector<pair<int,int>> res; // 결과값 pair를 집어넣기 위한 배열선언
if (plus > 0) {
res.push_back(calc(a,index+1,cur+a[index],plus-1,minus,mul,div));
}
if (minus > 0) {
res.push_back(calc(a,index+1,cur-a[index],plus,minus-1,mul,div));
}
if (mul > 0) {
res.push_back(calc(a,index+1,cur*a[index],plus,minus,mul-1,div));
}
if (div > 0) {
res.push_back(calc(a,index+1,cur/a[index],plus,minus,mul,div-1));
}
auto ans = res[0];
for (auto p : res) {
if (ans.first < p.first) {
ans.first = p.first; // 최대값 sorting
}
if (ans.second > p.second) {
ans.second = p.second; // 최소값 sorting
}
}
return ans;
}
int main() {
int n;
cin >> n;
vector<int> a(n); // 수열을 담기위한 배열선언
for (int i=0; i<n; i++) {
cin >> a[i];
}
int plus, minus, mul, div; // 연산자의 개수 설정
cin >> plus >> minus >> mul >> div;
auto p = calc(a, 1, a[0], plus, minus, mul, div); // 현재index의 전까지의 합을 cur로 두기때문에 두번째 index부터 계산해야함
cout << p.first << '\n';
cout << p.second << '\n';
return 0;
}
