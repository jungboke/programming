#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<tuple>
#include<string>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};


int main(){

    int m,n;
    cin >> m >> n;
    vector<string> a(n);
    int sx,sy;
    int ex,ey;
    sx = -1;
    sy = -1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == 'C')
            {
                if(sx == -1)
                {
                    sx = i;
                    sy = j;
                }
                else
                {
                ex = i;
                ey = j;
                }
            }
        }
    }
    vector<vector<int>> d(n,vector<int>(m,-1)); // d[n][m]
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    d[sx][sy] = 0;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(nx>=0&&nx<n&&ny>=0&&ny<m)
            {
                if(a[nx][ny]=='*') break;
                if(d[nx][ny] == -1)
                {
                q.push(make_pair(nx,ny));
                d[nx][ny] = d[x][y] + 1;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    cout << d[ex][ey] -1 << '\n';
    return 0;
}