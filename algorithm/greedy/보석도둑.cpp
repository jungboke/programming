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
sort(a.begin(), a.end(), [](jewel u, jewel v) {
return u.v > v.v;
});
multiset<int> s;
for (int i=0; i<k; i++) {
int t;
scanf("%d",&t);
s.insert(t);
}
long long ans = 0;
for (int i=0; i<n; i++) {
auto it = s.lower_bound(a[i].m);
if (it != s.end()) {
ans += a[i].v;
s.erase(it);
}
}
printf("%lld\n",ans);
return 0;
}