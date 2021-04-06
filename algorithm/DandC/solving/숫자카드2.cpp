#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> a(500000);
int binary_search(int k)
{
    int l = 0;
    int r = n-1;
    int ans1 = 0;
    int ans2 = 0;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(a[m] == k)
        {
            ans1 = m;
            r = m-1;
        }
        else if(a[m] < k)
        l = m + 1;
        else
        r = m - 1;
    }
    l = 0;
    r = n-1;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(a[m] == k)
        {
            ans2 = m + 1;
            l = m + 1;
        }
        else if(a[m] < k)
        l = m + 1;
        else
        r = m - 1;
    }

    int ans3 = ans2 - ans1;
    return ans3;    
}


int main() {
    /*
        lower bound(하한)는 같거나 큰것중에서 최솟값,
        upper bound(상한)는 큰것중에서 최솟값,
        upper bound에서 lower bound 빼면 중복되는 key값들의 개수가 나옴.
        vector를 쓰면 lower_bound, upper_bound 함수로 값을 한번에 구할수 있음.
        이분탐색에서 중복되는 key의 개수를 구하는 방법.
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.begin()+n);
    int m;
    cin >> m;
    while(m--)
    {
        int k;
        cin >> k;
        cout << binary_search(k) << " ";
    }
 
    cout << '\n';
    return 0;
}