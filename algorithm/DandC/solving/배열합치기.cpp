#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> result(n+m);
    for(int i=0;i<n;i++){

        cin >> a[i];
    }
    for(int i=0;i<m;i++){

        cin >> b[i];
    }
    merge(a.begin(),a.end(),b.begin(),b.end(),result.begin());
    for(int i=0;i<n+m;i++){

        cout << result[i] << " ";
    }
    cout << '\n';
    return 0;
}