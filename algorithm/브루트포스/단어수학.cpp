//모범답안
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
char alpha[256]; // 문자별 아스키코드 값을 담기위한 배열
int calc(vector<string> &a, vector<char> &letters, vector<int> &d) {
int m = letters.size();
int sum = 0;
for (int i=0; i<m; i++) {
alpha[letters[i]] = d[i]; // 문자별 순열들의 값 입력
}
for (string s : a) {
int now = 0;
for (char x : s) { // 단어별 값 계산
now = now * 10 + alpha[x];
}
sum += now;
}
return sum; // 단어들의 총합 
}
int main() {
int n;
cin >> n;
vector<string> a(n); // 단어를 담을 배열
vector<char> letters; // 단어를 구성하는 문자들을 담을 배열
for (int i=0; i<n; i++) {
cin >> a[i];
for (char x : a[i]) {
letters.push_back(x);
}
}
sort(letters.begin(), letters.end()); // letters의 중복되는 문자들을 제거 
letters.erase(unique(letters.begin(), letters.end()), letters.end());
int m = letters.size();
vector<int> d;
for (int i=9; i>9-m; i--) {
d.push_back(i);
}
sort(d.begin(), d.end()); // next_permutation을 돌리기 위한 초기 sorting 
int ans = 0;
do {
int now = calc(a, letters, d); 
if (ans < now) {
ans = now;
}
} while (next_permutation(d.begin(), d.end()));
cout << ans << '\n';
return 0;
}
