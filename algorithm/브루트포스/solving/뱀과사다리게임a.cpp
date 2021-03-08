#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int _next[200];
int dist[200];

int main(){

    int n,m;
    cin >> n >> m;
    for(int i=0;i<=100;i++)
    {
        _next[i] = i;
    }
    for(int i=0;i<n+m;i++)
    {
        int x1,y1;
        cin >> x1 >> y1;
        _next[x1] = y1;
    }
    memset(dist,-1,sizeof(dist));
    dist[0] = 0;
    queue<int> q;   
    q.push(1);
    dist[1] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=1;i<=6;i++)
        {
            if(x+i<=100&&dist[_next[x+i]]==-1)
            {
                q.push(_next[x+i]);
                dist[_next[x+i]] = dist[x] + 1;
            }
        }
    }
    cout << dist[100] << "\n";
    return 0;
}
