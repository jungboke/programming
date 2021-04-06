#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<int> a(500000);
int binary_search(int k)
{
    int l = 0;
    int r = n - 1;
    while(l<=r)
    {
        int m = (l+r)/2;
        if(a[m]==k)
        return 1;
        else if(a[m]<k)
        l = m + 1;
        else
        r = m - 1;
    }
    return 0;
}


int main() {
    /*
    binary search는 맨처음 index를 left, 마지막 index를 right, 중간 index를 middle로
    두고 key값이 middle보다 크면 left를 mid+1, 작으면 right를 mid-1로 이동하며
    left가 right보다 오른쪽으로 이동할때까지 key값을 검색하는 sorting 알고리즘.
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