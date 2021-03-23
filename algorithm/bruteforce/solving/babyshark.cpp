#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<string>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
tuple<int,int,int> bfs(vector<vector<int>> &a, int x, int y, int size)
{
    int n = a.size();
    vector<vector<int>> d(n,vector<int>(n,-1));
    vector<tuple<int,int,int>> ans;

    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 0;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&d[nx][ny]==-1)
            {
                bool ok = false;
                bool eat = false;
                if(a[nx][ny] == 0)
                ok = true;
                else if(a[nx][ny] < size)
                {
                    ok = true;
                    eat = true;
                }
                else if(a[nx][ny] == size)
                {
                    ok = true;
                }
                if(ok==true)
                {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                }
                if(eat==true)
                {
                    ans.push_back(make_tuple(d[nx][ny],nx,ny));
                }

            }
        }
    }    
    if(ans.empty())
    {
        return make_tuple(-1,-1,-1);
    }
    sort(ans.begin(),ans.end());
    return ans[0];
}

int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    int x,y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
            if(a[i][j] == 9)
            {
                tie(x,y) = make_pair(i,j);
                a[i][j] = 0;
            }
        }
    }
    int size = 2;
    int exp = 0;
    int ans = 0;
    while(true)
    {
        int dist,n,m;
        tie(dist,n,m) = bfs(a,x,y,size);
        if(dist == -1) break;
        a[n][m] = 0;
        ans += dist;
        exp++;
        if(exp == size)
        {
            size++;
            exp = 0;
        }
        tie(x,y) = make_pair(n,m);
    }

    cout << ans << '\n';

    return 0;
}