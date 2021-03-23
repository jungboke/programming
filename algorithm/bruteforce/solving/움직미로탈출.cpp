#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
using namespace std;
bool check[8][8][9];
int dx[] = {-1,-1,0,1,1,1,0,-1,0};
int dy[] = {0,1,1,1,0,-1,-1,-1,0};
int main() {

    vector<string> a(8);
    for(int i=0;i<8;i++)
    {
        cin >> a[i];
    }    
    queue<tuple<int,int,int>> q;
    q.push(make_tuple(7,0,0));
    check[7][0][0] = true;
    bool ans = false;
    while(!q.empty())
    {
        int x,y,t;
        tie(x,y,t) = q.front();
        q.pop();
        if(x==0&&y==7)
        {
            ans = true;
        }
        for(int i=0;i<9;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = min(t+1,8);
            if(nx>=0&&nx<8&&ny>=0&&ny<8)
            {
                if(nx-t>=0&&a[nx-t][ny] == '#') continue;
                if(nx-t-1>=0&&a[nx-t-1][ny] == '#') continue;
                if(check[nx][ny][nt] == false)
                {    
                    q.push(make_tuple(nx,ny,nt));
                    check[nx][ny][nt] = true;
                }
            }

        }
    }
    cout << (ans? 1 : 0) << '\n';
    return 0;
}