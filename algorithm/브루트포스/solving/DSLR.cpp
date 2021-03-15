#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<queue>
using namespace std;
vector<int> d(10001,-1);
vector<char> how(10001);
vector<int> from(10001);
void print(int s, int e)
{
    if(s==e)
    return;
    print(s,from[e]);
    cout << how[e];
}


int main(){
    
    int t;
    cin >> t;
    while(t--)
    {
        int s,e;
        cin >> s >> e;
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while(!q.empty())
        {
           
            int x = q.front();
            q.pop();
            int x1 = (x*2)%10000;
            if(d[x1] == -1)
            {
            q.push(x1);
            d[x1] = d[x] + 1;
            from[x1] = x;
            how[x1] = 'D';
            }
            int x2 = x-1;
            if(x2<0) x2 = 9999;
            if(d[x2] == -1)
            {
            q.push(x2);
            d[x2] = d[x] + 1;
            from[x2] = x;
            how[x2] = 'S';
            }
            int x3 = (x%1000) * 10 + (x/1000);
            if(d[x3] == -1)
            {
            q.push(x3);
            d[x3] = d[x] + 1;
            from[x3] = x;
            how[x3] = 'L';
            }
            int x4 = (x/10) + (x%10) * 1000;
            if(d[x4] == -1)
            {
            q.push(x4);
            d[x4] = d[x] + 1;
            from[x4] = x;
            how[x4] = 'R';
            }
        }
        print(s,e);
        cout << '\n';
        d.assign(10001,-1);
    }
    return 0;
}