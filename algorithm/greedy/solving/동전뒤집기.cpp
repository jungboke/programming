#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char flip(char cur)
{
    if(cur == 'T') return 'H';
    else return 'T';
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int ans = n*n;
    for(int state=0;state<(1<<n);state++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            int cnt = 0;
            for(int i=0;i<n;i++)
            {
                char cur = a[i][j];
                if(state&(1<<i))
                {
                    cur = flip(cur);
                }
                if(cur == 'T')
                {
                    cnt++;
                }
            }
            sum += min(cnt,n-cnt);
        }
        if(ans>sum) ans = sum;
    }
    cout << ans << '\n';
    return 0;
}

