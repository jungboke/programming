#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    // 현재 칸까지 만들수 있는 모든 증가수열의 경우의 수를 하나 하나 저장하는 것이
    // 아니라 일차원 배열에 겹쳐서 저장할 수 있음 대신 배열을 덮어쓰는거라 내용저장 불가
    // 획기적인 알고리즘임
    int n;
    cin >> n;
    vector<long long> a;
    for(int i=0;i<n;i++)
    {
        long long num;
        cin >> num;
        auto now = lower_bound(a.begin(),a.end(),num);
        if(now == a.end())
        {
            a.push_back(num);
        }
        else
        {
            *now = num;
        }
    }
    cout << a.size() << '\n';
    return 0;
}