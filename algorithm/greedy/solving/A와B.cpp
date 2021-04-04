#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    /*
        S에서 연산한번 진행시 길이 1개씩 늘어나므로 2의 (T length)-(S length)승
        만큼의 경우의수를 찾아야 만들수 있는지 알아 낼수 있음.
        그러나 연산의 뒤에 항상 A or B가 온다는 것을 생각해보면 T의 마지막 문자가
        A인지 B인지 확인해보면 마지막 연산이 무엇이였는지 확인가능함.
        이를 이용해서 T에서 S의 문자수까지 역연산을 진행해서 그게 S와 동일여부를
        판단하면 문제를 해결할수 있음.

        vector의 마지막 배열을 확인하는 방법 : t.back() / t.end()는 마지막 iterator임.
    */
    string s,t;
    cin >> s;
    cin >> t;
    while(t.length()>s.length())
    {
        if(t.back() == 'A')
        {
            t.pop_back();
        }
        else
        {
            t.pop_back();
            reverse(t.begin(),t.end());
        }
    }
    if(t==s) cout << 1 << '\n';
    else cout << 0 << '\n';
    
    return 0;
}