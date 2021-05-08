#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int ans2 = 0;
void sum(vector<int> eng, vector<string> a){
    int ans = 0;
    for(string s : a){
        int temp = 0;
        for(int i=0;i<s.size();i++){
            temp = temp * 10 + eng[s[i]];
        }
        ans += temp;
    }
    if(ans2 < ans) ans2 = ans;
}
int main() {

    int n;
    cin >> n;
    vector<string> a(n);
    vector<char> alpha;
    vector<int> num;
    vector<int> eng(256);
    for(int i=0;i<n;i++){
        cin >> a[i];
        for(int j=0;j<a[i].size();j++){
            alpha.push_back(a[i][j]);
        }
    }
    sort(alpha.begin(),alpha.end());
    alpha.erase(unique(alpha.begin(),alpha.end()),alpha.end());
    for(int i=0;i<alpha.size();i++){
        num.push_back(9-i);
    }
    sort(num.begin(),num.end());
    do{
        for(int i=0;i<alpha.size();i++){
            eng[alpha[i]] = num[i];
        }
        sum(eng,a);
    }while(next_permutation(num.begin(),num.end()));
    cout << ans2 << '\n';
    return 0;
}