#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second > b.second); 
}


int main() {

    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    
    multiset<long long> s;
    for(int i=0;i<k;i++)
    {
        long long c;
        cin >> c;
        s.insert(c);
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        auto p = s.lower_bound(a[i].first);
        if(p!=s.end())
        {
            ans += a[i].second;
            s.erase(p);
        }       
    }

    cout << ans << '\n';
    return 0;
}