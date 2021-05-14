#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }    
    vector<int> team(n);
    vector<int> ans;
    for(int i=0;i<n/2;i++){
        team[i] = 1;
    }
    sort(team.begin(),team.end());
    do{
        vector<int> start;
        vector<int> link;
        int temp1 = 0;
        int temp2 = 0;
        for(int i=0;i<team.size();i++){
            if(team[i] == 0) start.push_back(i);
            else link.push_back(i);
        }
        for(int i=0;i<start.size();i++){
            for(int j=0;j<start.size();j++){
                if(i==j) continue;
                temp1 += (a[start[i]][start[j]]);
                temp2 += (a[link[i]][link[j]]);
            }
        }
        ans.push_back(abs(temp1-temp2));        

    }while(next_permutation(team.begin(),team.end()));

    cout << *min_element(ans.begin(),ans.end()) << '\n';
    return 0;
}