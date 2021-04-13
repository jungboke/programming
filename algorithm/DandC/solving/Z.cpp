#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int k = 0;
int power2(int n){
    return (1<<n);
}
int a[3000][3000];
void solve(int n, int x, int y){
    if(n==1){
        a[x][y] = k++;
        return;
    }
    int m = n/2;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            solve(m,x+i*m,y+j*m);
        }
    }
}

int main() {

    int n, r, c;
    cin >> n >> r >> c;
    solve(power2(n),0,0);
    cout << a[r][c] << '\n'; 
    return 0;
}