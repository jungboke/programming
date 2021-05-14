#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<int> op;
    for(int i=0;i<4;i++){ // 0 : +, 1 : -, 2 : x, 3 : /
        int x;
        cin >> x;
        for(int k=0;k<x;k++){
            op.push_back(i);
        }
    }
    sort(op.begin(),op.end());
    vector<int> ans;
    do{
        int temp = a[0];
        for(int i=0;i<n-1;i++){
            if(op[i] == 0) temp = temp + a[i+1];
            else if(op[i] == 1) temp = temp - a[i+1];
            else if(op[i] == 2) temp = temp * a[i+1];
            else temp = temp / a[i+1];           
        }
        ans.push_back(temp);

    }while(next_permutation(op.begin(),op.end()));
    cout << *max_element(ans.begin(),ans.end()) << '\n';
    cout << *min_element(ans.begin(),ans.end()) << '\n';

    return 0;
}