#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<string>
using namespace std;
vector<vector<int>> check(1600,vector<int>(1600,0));

int main() {
    
    int a,b,c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    queue<pair<int,int>> q;
    q.push(make_pair(a,b));
    check[a][b] = 1;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        int z = (a+b+c)-x-y;
        
        if(x>y)
        {
            int nx = x-y;
            int ny = y+y;
            if(nx>=1&&nx<=1600&&ny>=1&&ny<=1600&&check[nx][ny]==0)
            {
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
            }
        }
        if(x<y)
        {
            int nx = x+x;
            int ny = y-x;
            if(nx>=1&&nx<=1600&&ny>=1&&ny<=1600&&check[nx][ny]==0)
            {
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
            }
        }
        if(x<z)
        {
            int nx = x+x;
            int ny = y;
            if(nx>=1&&nx<=1600&&ny>=1&&ny<=1600&&check[nx][ny]==0)
            {
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
            }
        }
        if(x>z)
        {
            int nx = x-z;
            int ny = y;
            if(nx>=1&&nx<=1600&&ny>=1&&ny<=1600&&check[nx][ny]==0)
            {
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
            }
        }
        if(y<z)
        {
            int nx = x;
            int ny = y+y;
            if(nx>=1&&nx<=1600&&ny>=1&&ny<=1600&&check[nx][ny]==0)
            {
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
            }
        }
        if(y>z)
        {
            int nx = x;
            int ny = y-z;
            if(nx>=1&&nx<=1600&&ny>=1&&ny<=1600&&check[nx][ny]==0)
            {
                q.push(make_pair(nx,ny));
                check[nx][ny] = 1;
            }
        }
        
    }
    if(sum%3!=0)
    {
        cout << 0 << '\n';
        return 0;
    }
    if(check[sum/3][sum/3])
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
    return 0;
}