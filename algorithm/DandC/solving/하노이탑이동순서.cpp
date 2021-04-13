#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
맨 아래의 가장큰 판을 옮기기 위해 전체를 옮기려는 탑이 아닌 나머지 탑에 큰판 이전의
나머지 칸들을 옮기고 그후 가장 큰판을 옮기려는 탑에 옮긴후 나머지 판들이 있는 탑에서
옮기려는 탑으로 나머지 판들을 옮기는 과정을 재귀로 계속 반복.
solve(int n, int x, int y) : n(1~n판을 옮김), x(현재 탑), y(옮기려는 탑)
*/
void solve(int n, int x, int y){
    if(n==0){
        return;
    }
    solve(n-1,x,6-x-y);
    cout << x << " " << y << '\n';
    solve(n-1,6-x-y,y);
}

int main() {

    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n';
    solve(n,1,3);
    return 0;
}