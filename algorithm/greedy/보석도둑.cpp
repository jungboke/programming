//모범답안
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct jewel {
int m, v;
};
int main() {
int n,k;
scanf("%d %d",&n,&k);
vector<jewel> a(n);
for (int i=0; i<n; i++) {
scanf("%d %d",&a[i].m, &a[i].v);
}
sort(a.begin(), a.end(), [](jewel u, jewel v) { // 보석의 무게와 가격의 pair vector를 가격내림차순으로 sorting
return u.v > v.v;
});
multiset<int> s; // multiset은 set과 다르게 중복되는 key값을 넣을수 있음
for (int i=0; i<k; i++) {
int t;
scanf("%d",&t);
s.insert(t);
}
long long ans = 0;
for (int i=0; i<n; i++) {
auto it = s.lower_bound(a[i].m); // 인자 값보다 같거나 큰값중 최솟값을 구하는 lower_bound 함수
// lower_bound 의 return 형은 iterator라서 auto로 받아줘야함
if (it != s.end()) { // set의 end()는 마지막 원소가 아닌 그 다음의 iterator
ans += a[i].v;
s.erase(it); // 선택된 가방 지우기
}
}
printf("%lld\n",ans);
return 0;
}