#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    if(a.second==b.second)
    {
        return (a.first < b.first);
    }
    else
    {
        return (a.second < b.second);
    }
}


int main() {

    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    int now = 0;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        if(now<=a[i].first)
        {
            now = a[i].second;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}