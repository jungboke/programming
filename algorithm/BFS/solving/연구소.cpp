#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a[10][10];
int temp[10][10];
bool check[10][10];
int n,m;
int bfs()
{
    queue<pair<int,int>> q;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            temp[i][j] = a[i][j];
            if(temp[i][j] == 2)
            {
                q.push(make_pair(i,j));
            }
        }
    }    
                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++)
                    {
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(nx>=0&&nx<n&&ny>=0&&ny<m)
                        {
                            if(temp[nx][ny]==0)
                            {
                                q.push(make_pair(nx,ny));
                                temp[nx][ny] = 2;
                            }
                        }
                    }
                }                
                 

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(temp[i][j]==0)
                ans++;
        }
    }
    return ans;
}




int main(){

    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int x1=0;x1<n;x1++)
    {
        for(int y1=0;y1<m;y1++)
        {
            if(a[x1][y1]!=0) continue;
            for(int x2=0;x2<n;x2++)
            {
                for(int y2=0;y2<m;y2++)
                {
                    if(a[x2][y2]!=0) continue;
                    if(x1==x2&&y1==y2) continue;
                    for(int x3=0;x3<n;x3++)
                    {
                        for(int y3=0;y3<m;y3++)
                        {
                            if(a[x3][y3]!=0) continue;                            
                            if(x2==x3&&y2==y3) continue;
                            if(x1==x3&&y1==y3) continue;
                            a[x1][y1] = 1;
                            a[x2][y2] = 1;
                            a[x3][y3] = 1;
                            
                            int cur = bfs();
                            if(cur>ans) ans = cur;
                            a[x1][y1] = 0;
                            a[x2][y2] = 0;
                            a[x3][y3] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}