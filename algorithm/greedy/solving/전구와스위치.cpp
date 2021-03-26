#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void change(string &a,int index)
{
    int n = a.length();
    for(int i=index-1;i<=index+1;i++)
    {
        if(i>=0&&i<n)
        {
            a[i] = '1' - a[i] + '0';
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    string a,b,c;
    cin >> a;
    cin >> b;
    c = a;
    int ans1 = 0;
    int ans2 = 1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=b[i])
        {
            change(a,i+1);
            ans1++;
        }
    }
    if(a!=b) ans1 = -1;
    
    a = c;
    change(a,0);
    for(int i=0;i<n-1;i++)
    {
        if(a[i]!=b[i])
        {
            change(a,i+1);
            ans2++;
        }
    }
    if(a!=b) ans2 = -1;
    
    if(ans1==-1&&ans2==-1)
    cout << -1 << '\n';
    else if(ans1==-1)
    cout << ans2 << '\n';
    else if(ans2==-1)
    cout << ans1 << '\n';
    else
    cout << min(ans1,ans2) << '\n';

    return 0;
}
