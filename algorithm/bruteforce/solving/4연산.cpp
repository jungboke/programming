#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#include<string>
#include<set>
using namespace std;
const long long limit = 1000000000LL;
set<long long> check;
int main(){

    long long s,e;
    cin >> s >> e;
    queue<pair<long long,string>> q;
    q.push(make_pair(s,""));
    check.insert(s);
    string str;
    while(!q.empty())
    {
        long long x;
        tie(x,str) = q.front();
        q.pop();
        if(x == e)
        {
            if(str.length() == 0)
            {
                str = "0";
            }
            cout << str << '\n';
            return 0;
        }
        long long x1 = x*x;
        if(x1 >=0 && check.count(x1) == 0 && x1 <= limit)
        {
            q.push(make_pair(x1,str+'*'));
            check.insert(x1);
        }
        long long x2 = 2*x;
        if(x2 >=0 && check.count(x2) == 0 && x2 <= limit)
        {
            q.push(make_pair(x2,str+'+'));
            check.insert(x2);
        }
        long long x3 = 0;
        if(x3 >=0 && check.count(x3) == 0 && x3 <= limit)
        {
            q.push(make_pair(x3,str+'-'));
            check.insert(x3);
        }
        long long x4 = x/x;
        if(x4 >0 && check.count(x4) == 0 && x4 <= limit)
        {
            q.push(make_pair(x4,str+'/'));
            check.insert(x4);
        }
    }
    cout << -1 << '\n';
    return 0;
}