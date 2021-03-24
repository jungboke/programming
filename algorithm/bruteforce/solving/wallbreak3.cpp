#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
#include<algorithm>
using namespace std;
int d[1010][1010][11][2];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main() {

    memset(d,-1,sizeof(d));
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    } 
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0,0,k,0));
    d[0][0][k][0] = 1;
    while(!q.empty())
    {
        int x,y,t,day;
        tie(x,y,t,day) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m)
            {
                if(a[nx][ny] == '0'&&d[nx][ny][t][1-day] == -1)
                {
                    q.push(make_tuple(nx,ny,t,1-day));
                    d[nx][ny][t][1-day] = d[x][y][t][day] + 1; 
                }
                else if(day==0&&a[nx][ny] == '1'&&t != 0&&d[nx][ny][t-1][1-day] == -1)
                {
                    q.push(make_tuple(nx,ny,t-1,1-day));
                    d[nx][ny][t-1][1-day] = d[x][y][t][day] + 1; 
                }
            }                        
        }
        if(d[x][y][t][1-day] == -1)
        {
            q.push(make_tuple(x,y,t,1-day));
            d[x][y][t][1-day] = d[x][y][t][day] + 1;
        }
    }
    int ans = -3;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<2;j++)
        {
            if((ans==-3||ans>d[n-1][m-1][i][j])&&d[n-1][m-1][i][j]!=-1)
            ans = d[n-1][m-1][i][j];
        }
    }
    if(ans==-3)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }


    return 0;
}