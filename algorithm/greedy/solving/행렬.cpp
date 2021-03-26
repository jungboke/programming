#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;

void flip(int x, int y, vector<string> &a)
{
    for(int i=x-1;i<=x+1;i++)
    {
        for(int j=y-1;j<=y+1;j++)
        {
            a[i][j] = ('1' - a[i][j]) + '0';
            /*if(a[i][j] == '0') a[i][j] = '1';
            else if(a[i][j] == '1') a[i][j] = '0';*/
        }
    }
}



int main(){

    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(n);
    
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    
    for(int i=0;i<n;i++)
    {
        cin >> b[i];
    }

    int ans = 0;

    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<m-2;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                flip(i+1,j+1,a);
                ans++;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] != b[i][j])
            {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}