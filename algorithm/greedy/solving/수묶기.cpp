#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    /*
        양수는 큰수끼리 묶고, 음수는 작은수끼리 묶고, 1은 묶지 않고 더하면
        최대값을 구할수 있음.
        plus와 minus vector는 2개씩 묶일수 있도록 하기 위해 plus가 홀수면 1을
        추가하고 minus가 홀수면 0이 있을때 추가하여 혼자 남은 음수하나랑 묶어주고
        0이 없다면 1을 추가해주는 방식을 사용.

        오름차수는 기본sort() 이용하면 되고, 내림차수는 sort()를 한뒤 reverse()
        를 하면됨.
    */
    int n;
    cin >> n;
    vector<int> plus;
    vector<int> minus;
    int one = 0;
    int zero = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==1) one++;
        else if(x>0) plus.push_back(x);
        else if(x<0) minus.push_back(x);
        else zero++;
    }
    if(plus.size()%2==1)
    {
        plus.push_back(1);
    }
    if(minus.size()%2==1)
    {
        minus.push_back(zero>0?0:1);
    }
    sort(plus.begin(),plus.end());
    reverse(plus.begin(),plus.end());
    sort(minus.begin(),minus.end());   
    int ans = one;
    for(int i=0;i<plus.size();i+=2)
    {
        ans += plus[i] * plus[i+1];
    }
    for(int i=0;i<minus.size();i+=2)
    {
        ans += minus[i] * minus[i+1];
    }
    cout << ans << '\n';
    return 0;
}