#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    /*
        30의 배수가 되기 위해서는 2*3*5 이기 때문에 2,3,5의 배수여야함.
        2의 배수는 끝자리가 2,4,6,8,0 이고 5의 배수는 끝자리가 0,5이기 때문에
        원하는 수의 끝자리는 항상 0이여야 하고, 3의 배수의 특징은 모든 자리수의
        합이 3의배수이기 때문에 30의 배수의 총특징은 끝자리 0, 모든 자리수의 합
        3의 배수여야함. 그리고 수를 재배열해서 가장 큰수는 내림차 순이므로 이
        방식을 활용.

        string 배열도 sort() 함수를 사용하여 정렬할수 있음.
    */
    string n;
    cin >> n;
    int sum = 0;
    for(char c:n)
    {
        sum += c -'0';
    }
    sort(n.begin(),n.end());
    if(n[0]=='0'&&sum%3==0)
    {
        reverse(n.begin(),n.end());
        cout << n << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
    return 0;
}