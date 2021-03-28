#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second>b.second);
}

int main() { // 보석도둑 문제 가방기준으로 풀때와 비슷함
             // 현재날짜보다 같거나 큰 날짜의 강연이여야 실행가능함
    int n;
    cin >> n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    priority_queue<int> q; // queue에 값집어넣으면 top은 가장 먼저 들어간게 아닌 가장 큰 값이 됨
    int ans = 0;
    int k = 0;
    for(int i=10000;i>=1;i--)
    {
        while(k<n&&a[k].second == i) // while에 k<n 식으로 브레이크 안넣어주면 마지막 index에서 overflow발생
        {
            q.push(a[k].first);
            k++;
        }
        if(!q.empty())
        {
            ans += q.top();
            q.pop();
        }
    }

    cout << ans << '\n';
    return 0;
}