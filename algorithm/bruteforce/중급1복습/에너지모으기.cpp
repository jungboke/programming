#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
void go(vector<int> &a, int sum){
    if(a.size()==2){
        ans.push_back(sum);
        return;
    }
    for(int i=1;i<a.size()-1;i++){
        int temp = a[i-1] * a[i+1];
        vector<int> b(a);
        b.erase(b.begin()+i);
        go(b,sum+temp);
    }
}



int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    go(a,0);
    cout << *max_element(ans.begin(),ans.end()) << '\n';
    return 0;
}