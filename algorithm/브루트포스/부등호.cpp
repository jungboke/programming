//모범답안
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check(vector<int> &perm, vector<char> &a) {
for (int i=0; i<a.size(); i++) {
if (a[i] == '<' && perm[i] > perm[i+1]) {
return false;
}
if (a[i] == '>' && perm[i] < perm[i+1]) {
return false;
}
}
return true;
}
int main() {
int k;
cin >> k;
vector<char> a(k); // 부등호를 담기위한 배열 선언
for (int i=0; i<k; i++) {
cin >> a[i]; // k개의 부등호 입력
}
vector<int> small(k+1); // 최소값을 담기위한 배열 선언
vector<int> big(k+1); // 최대값을 담기위한 배열 선언
for (int i=0; i<=k; i++) {
small[i] = i;
big[i] = 9-i;
}
do { // 최소값을 담은 배열의 순열들을 구하기 위한 dowhile문
if (check(small, a)) {
break;
}
} while(next_permutation(small.begin(), small.end()));
do {
if (check(big, a)) {
break;
}
} while(prev_permutation(big.begin(), big.end()));
for (int i=0; i<big.size(); i++) {
cout << big[i]; // 최대값 배열 출력
}
cout << '\n';
for (int i=0; i<small.size(); i++) {
cout << small[i]; // 최소값 배열 
}
cout << '\n';
return 0;
}
