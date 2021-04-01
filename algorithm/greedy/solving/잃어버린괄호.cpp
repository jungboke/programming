#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    /*
    숫자와 연산자로 이루어진 string에서 숫자와 연산자를 나눠
    따로 vector에 집어넣는 알고리즘. 맨앞에 + 붙여주면 숫자와 연산자
    1 pair씩 묶을수 있음.
    */
    string s;
    cin >> s;
    vector<int> sign;
    vector<int> num;
    sign.push_back(1);
    int cur = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-'||s[i]=='+')
        {
            if(s[i]=='-') sign.push_back(-1);
            else sign.push_back(1);
            num.push_back(cur);
            cur=0;
        }
        else
        {
            cur = cur * 10 + (s[i] - '0');
        }    
    }
    num.push_back(cur); // 마지막 숫자는 강제로 num에 넣음
    int ans = 0;
    bool minus = false;
    for(int i=0;i<sign.size();i++)
    {
        if(sign[i] == -1)
        {
            minus = true;
        }
        
        if(minus==true)
        {
            ans -= num[i];
        }
        else
        {
            ans += num[i];
        }
    }
    cout << ans << '\n';
    return 0;
}