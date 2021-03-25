#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int e = 0;
    for(int i=0;i<n;i++)
    {
        if((k/a[i])==0) break;
        e = i;
    }
    int ans = 0;
    int temp = k;
    for(int i=e;i>=0;i--)
    {
        if(temp == 0) break;
        ans += (temp/a[i]);
        temp = temp - a[i] * (temp/a[i]); 
    }
    cout << ans << '\n';
    return 0;
}