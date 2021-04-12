#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
same함수를 통해 해당 칸들이 모두 같은지 확인하며 
9등분해나가는 bottom-up방식의 알고리즘문제.
*/
vector<vector<int>> a(3000,vector<int>(3000,0));
vector<int> cnt(3);
bool same(int x, int y, int n){

    for(int i=x;i<x+n;i++){

        for(int j=y;j<y+n;j++){

            if(a[x][y] != a[i][j]){

                return false;
            }
        }
    }
    return true;
}

void solve(int x, int y, int n){

    if(same(x,y,n)){

        cnt[a[x][y]+1]++;
        return;
    }
    int m = n/3;
    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            solve(x+m*i, y+m*j, m);
        }
    }

}


int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    solve(0,0,n);
    for(int i=0;i<3;i++){
        cout << cnt[i] << '\n';
    }
    return 0;
}