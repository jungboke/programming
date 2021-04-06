#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int num = 1;
int num2 = 1;

void bfs(vector<string> &a, vector<vector<int>> &b, int x, int y)
{
    int n = a.size();
    vector<vector<bool>> check(n,vector<bool>(n,false));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = true;
    b[x][y] = num; 
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n)
            {
                if(a[nx][ny]==a[x][y]&&check[nx][ny]==false)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    b[nx][ny] = num;  
                }
            }
        }
    }

}
void dbfs(vector<string> &a, vector<vector<int>> &b, int x, int y)
{
    int n = a.size();
    vector<vector<bool>> check(n,vector<bool>(n,false));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = true;
    b[x][y] = num; 
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n)
            {
                if(a[nx][ny]==a[x][y]&&check[nx][ny]==false)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    b[nx][ny] = num;  
                }
                else if(a[x][y]=='R'&&a[nx][ny]=='G'&&check[nx][ny]==false)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    b[nx][ny] = num;  
                }
                else if(a[x][y]=='G'&&a[nx][ny]=='R'&&check[nx][ny]==false)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    b[nx][ny] = num;  
                }
            }
        }
    }

}



int main() {

    int n;
    cin >> n;
    vector<string> a(n);
    vector<vector<int>> sector(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(sector[i][j] == 0)
            {
                bfs(a,sector,i,j);
                num++;
            }
        }
    }
    sector.assign(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(sector[i][j] == 0)
            {
                dbfs(a,sector,i,j);
                num2++;
            }
        }
    }
    cout << num-1 << ' ' <<  num2-1 <<  '\n';
    

    return 0;
}