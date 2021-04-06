#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<string>
#include<cstring>
using namespace std;
vector<int> dist(10001,-1);
bool prime[10001];
int main() {

    for (int i=2; i<=10000; i++) {
        if (prime[i] == false) {
            for (int j=i*i; j <= 10000; j+=i) {
                prime[j] = true;
            }
        }
    }
    for (int i=0; i<=10000; i++) {
        prime[i] = !prime[i];
    }
    
    int t;
    cin >> t;
    while(t--)
    {
        dist.assign(10001,-1);
        string s,e;
        cin >> s >> e;
        queue<string> q;
        q.push(s);
        dist[stoi(s)] = 0;
        while(!q.empty())
        {
            string x = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                string y = x;
                for(int j=0;j<=9;j++)
                {
                    y[i] = j + '0';
                    int iy = stoi(y);
                    if(iy>=1000 && prime[iy] == true && dist[iy] == -1)
                    {
                        q.push(y);
                        dist[iy] = dist[stoi(x)] + 1;
                    }

                }
            }
        }
        if(dist[stoi(e)] == -1)
        cout << "Impossible" << '\n';
        else
        cout << dist[stoi(e)] << '\n';
    }

    return 0;
}