#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#include<tuple>
using namespace std;
int dist[1010][1010][11];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main() {

    memset(dist,-1,sizeof(dist));
    int n,m,k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,k));
    dist[0][0][k] = 1;
    while(!q.empty())
    {
        int x,y,t;
        tie(x,y,t) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m)
            {
                if(a[nx][ny] == '0'&&dist[nx][ny][t] == -1)
                {
                    q.push(make_tuple(nx,ny,t));
                    dist[nx][ny][t] = dist[x][y][t] + 1;
                }
                else if(a[nx][ny] == '1'&&t!=0&&dist[nx][ny][t-1] == -1)
                {
                    q.push(make_tuple(nx,ny,t-1));
                    dist[nx][ny][t-1] = dist[x][y][t] + 1;
                }
            }
        } 
    }
    int ans = -3;
    for(int i=0;i<=k;i++)
    {
        if((ans == -3 || dist[n-1][m-1][i] < ans) && dist[n-1][m-1][i] != -1)
        {
            ans = dist[n-1][m-1][i];
        }
    }
    if(ans == -3)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    } 
    return 0;
}