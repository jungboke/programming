#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<string>
#include<queue>
using namespace std;
vector<int> d(10001,-1);
int main(){
    
    int t;
    cin >> t;
    while(t--)
    {
        d.assign(10001,-1);
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
            }
            int x2 = x-1;
            if(x2<0) x2 = 9999;
            if(d[x2] == -1)
            {
            q.push(x2);
            d[x2] = d[x] + 1;
            }
            int x3 = (x%1000) * 10 + (x/1000);
            if(d[x3] == -1)
            {
            q.push(x3);
            d[x3] = d[x] + 1;
            }
            int x4 = (x/10) + (x%10) * 1000;
            if(d[x4] == -1)
            {
            q.push(x4);
            d[x4] = d[x] + 1;
            }
        }
        cout << d[e] << '\n';
        
    }
    return 0;
}