#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<cstring>
using namespace std;
int dist[1010][1010][2];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main() {

    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    memset(dist,-1,sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(0,0,1));
    dist[0][0][1] = 1;
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
                else if(a[nx][ny] == '1'&&t==1&&dist[nx][ny][t-1] == -1)
                {
                        q.push(make_tuple(nx,ny,t-1));
                        dist[nx][ny][t-1] = dist[x][y][t] + 1;
                }
            }

        } 
        
    }
    if(dist[n-1][m-1][0] != -1 && dist[n-1][m-1][1] != -1)
    {
        cout << min(dist[n-1][m-1][0],dist[n-1][m-1][1]) << '\n';
    }
    else if(dist[n-1][m-1][0] == -1 && dist[n-1][m-1][1] == -1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << max(dist[n-1][m-1][0],dist[n-1][m-1][1]) << '\n';
    }
    return 0;
}